/*

Topic: Threads and Synchronization
Question: There are multiple users calling a method reg_cb at different intances of time, as shown below. Simultaneously, there is an event happening. All the user requests that were made during the execution of the event should wait till the event completes and then execute the reg_cb method. Once the event is finished, the user requests to the reg_cb method can be executed immediatly. Implement how to handle the given scenario.


					Event in progress
----|---------------|--------------------|-------------------|--------------> timeline
U1: reg_cb(f1)     U2: reg_cb(f2)      Event completed      U3:reg_cb(f3)
									   (execute f1,f2)      (execute f3)
Was asked many questions on basic fundamentals like,


When does a concurrant modification exception occur?
When is the possibility of same thread (user x) calling the reg_cb() twice?
What are the possible deadlock scenarios?
What is mutex? etc..

*/

// Use mutex to lock execution of reg_cb while event happening
// When event unlocked, process all reg_cb calls in queue
// Also process any additional calls immediately

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <deque>
#include <functional>
#include <mutex>

class threadHandler {
private:
    std::atomic<bool> _event_happening{false};
    std::mutex _mtx;
    std::deque<std::function<void()>> _Q;

public:
    void startEvent(){
        _event_happening.store(true);
    }

    void endEvent(){
        _event_happening.store(false);
        // Acquire lock before entering critical section
        std::scoped_lock lock(_mtx);
        while(!_Q.empty()){
            std::function<void()> callback = _Q.front();
            _Q.pop_front();
            callback();
        }
        // Lock automatically released on exit of critical section when it goes out of scope here
    }

    void reg_cb(std::function<void()> callback){
        if(_event_happening.load()){
            // Any changes to non-atomic shared memory are a "critical section" and must be guarded by a mutex lock
            std::scoped_lock lock(_mtx);
            _Q.push_back(callback);
            // Lock automatically released on exit of critical section when it goes out of scope here
        }
        else {
            callback();
        }
    }
};

// Test case functions
void testFunction1() {
    std::cout << "Function 1 executed.\n";
}

void testFunction2() {
    std::cout << "Function 2 executed.\n";
}

void testFunction3() {
    std::cout << "Function 3 executed.\n";
}

int main() {
    threadHandler handler;

    // Start event
    handler.startEvent();

    // Simulate user requests
    std::thread t1([&handler]() { handler.reg_cb(testFunction1); });
    std::thread t2([&handler]() { handler.reg_cb(testFunction2); });

    // Simulate event completion after some time
    std::this_thread::sleep_for(std::chrono::seconds(2));
    handler.endEvent();

    t1.join();
    t2.join();

    // New request after the event is completed
    handler.reg_cb(testFunction3);

    return 0;
}
