/*
Design an IdManager.

IdManager manages a pool of integer ids. (from 1 to n). It should provide 

apis to get_id() and free_id()

get_id(): It returns any id , available in the pool. An Id cannot be given away

again, unless it has been freed.

free_id(): It returns the id back to the pool, so that it can be given out

again.

Discuss the apis definitions, data structures and write tests.
*/

#include <iostream>
#include <unordered_set>

struct Node
{
    int _id;
    Node* _next;
    Node* _prev;

    Node(int i) : _id(i), _next(nullptr), _prev(nullptr) {};
};

class Q {
private:
    Node* _front;
    Node* _back;

public:
    Q() : _front(nullptr), _back(nullptr) {};
    Q(Node* p) : _front(p), _back(p) {};

    ~Q(){
        while(_front){
            Node* t = _front;
            _front = _front->_next;
            delete t;
        }
    }

    int back() {
        return _back->_id;
    }

    void push_back(int i) {
        Node* p = new Node(i);
        if(empty()){
            _front = p;
            _back = p;
        }
        else {
            p->_prev = _back;
            _back->_next = p;
            _back = _back->_next;
        }
    }

    void pop_back() {
        Node* p = _back;
        _back = _back->_prev;
        _back->_next = nullptr;
        delete p;
    }

    int front() {
        return _front->_id;
    }

    void push_front(int i) {
        Node* p = new Node(i);
        if (empty()) {
            _front = p;
            _back = p;
        } else {
            p->_next = _front;
            _front->_prev = p;
            _front = p;
        }
    }

    void pop_front() {
        Node* p = _front;
        _front = _front->_next;
        _front->_prev = nullptr;
        delete p;
    }

    bool empty() {
        return (_front == nullptr);
    }

    void printQ() {
        if(_front == nullptr){
            std::cout << "Empty" << "\n";
            return;
        }

        Node* p = _front;
        while(p){
            std::cout << p->_id << ' ';
            p = p->_next;
        }
        std::cout << "\n";
    }
};


class IdManager {
    private:
        Q _avail;
        std::unordered_set<int> _active;
    
    public:
        IdManager(int n) {
            for(int i=1; i<=n; ++i){
                _avail.push_back(i);
            }
        }

        int get_id() {
            if(_avail.empty()){
                throw std::runtime_error("No available ids");
            }
            int id = _avail.front();
            _avail.pop_front();
            _active.insert(id);
            return id;
        }

        void free_id(int id) {
            if(_active.find(id) == _active.end()){
                throw std::runtime_error("ID not in use");
            }
            _active.erase(id);
            _avail.push_back(id);
        }
};


int main() {
    Q q;
    q.printQ();

    q.push_back(1);
    q.printQ();

    q.push_front(2);
    q.printQ();

    q.pop_front();
    q.push_back(3);
    q.push_back(3);
    q.push_back(3);
    q.pop_back();
    q.printQ();

    return 0;
}