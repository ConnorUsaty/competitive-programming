#include <iostream>
#include <vector>
#include <unordered_map>

template <typename T>
class Set {
private:
    std::vector<T> _v;
    std::unordered_map<T, int> _mp;

public:
    void insert(T t){
        if(_mp.find(t)!=_mp.end()){
            return;
        }
        _mp.insert({t, (int)_v.size()});
        _v.push_back(t);
    }

    void remove(T t){
        if(_mp.find(t)==_mp.end()){
            return;
        }
        T last_val = _v[_v.size()-1];
        std::swap(_v[_v.size()-1], _v[_mp[t]]);
        _mp[last_val] = _mp[t];
        _mp.erase(t);
        _v.pop_back();
    }

    bool search(T t) {
        return (_mp.find(t) != _mp.end());
    }

    int returnRandElement() {
        if(_v.size() == 0){
            throw std::runtime_error("No elements in set.");
        }
        std::srand(1);
        return _v[rand() % (int)_v.size()];
    }

    void printSet(){
        if(_v.size() == 0){
            std::cout << "EMPTY\n";
            return;
        }
        for(auto t : _v) std::cout << t << ' ';
        std::cout << "\n";
    }
};

// Attempt to make hashing one without STL hashing container (no std map or sets)
/*
To acheive amortized O(1) without using any STL hashing containers we must hash ourselves
We must make a hash() function uses std::hash<T>{}(t)
We must make a resize function to ensure there is always space for the next insertion
We must properly track both the size and capacity to ensure the above functions word
We must make a default constructor and choose our default capacity and our default value
When doing remove, or search we have to also make sure that i<_capacity so that there is no inf loop if all spots are filled with non t value
When doing remove or insert we have to check if the element is removed or inserted to properly track the size variable
Test cases should have at least one for each function possibility, i.e. insert normal, insert duplicate, insert req resize, insert duplicate req resize
*/
template <typename T>
class HashSet {
private:
    std::vector<T> _v;
    int _capacity;
    int _size;

    int hash(T t) {
        return std::hash<T>{}(t) % _capacity;
    }

    void resize() {
        int old_capacity = _capacity;
        _capacity *= 2;
        std::vector<T> old_v = _v;
        _v.clear();
        _v.resize(_capacity, -2);

        for(int i=0; i<old_capacity; ++i){
            insert(old_v[i]);
        }
    }

public:
    HashSet() : _v(10, -2), _capacity(10), _size(0) {};

    void insert(T t) {
        if(_size == _capacity){
            resize();
        }
        int h = hash(t);
        int i = 0;
        while(_v[h]!=-2 && _v[h]!=t){
            h = (h+1) % _capacity;
        }
        if(_v[h]!=t){
            _v[h] = t;
            _size++;
        }
    }

    void remove(T t){
        int h = hash(t);
        int i = 0;
        while(_v[h]!=-2 && _v[h]!=t && i<_capacity){
            h = (h+1) % _capacity;
            i++;
        }
        if(_v[h]==t){
            _v[h]=-1;
            _size--;
        }
    }

    bool search(T t){
        int h = hash(t);
        int i = 0;
        while(_v[h]!=-2 && _v[h]!=t && i<_capacity){
            h = (h+1) % _capacity;
        }
        return (_v[h] == t);
    }

    T returnRandElement() {
        int h = rand();
        return _v[h];
    }
    
    void printSet(){
        if(_v.size() == 0){
            std::cout << "EMPTY\n";
            return;
        }
        for(auto t : _v) std::cout << t << ' ';
        std::cout << "\n";
    }
};

int main() {
    HashSet<int> s;
    s.printSet();

    s.insert(1);
    s.printSet();

    s.remove(2);
    s.remove(1);
    s.printSet();

    s.insert(4);
    s.insert(85);
    s.insert(85);
    s.insert(85);
    s.printSet();

    // std::cout << s.returnRandElement() << "\n";
    // std::cout << s.returnRandElement() << "\n";
    // std::cout << s.returnRandElement() << "\n";

    std::cout << s.search(4) << "\n";
    s.remove(4);
    s.printSet();
    std::cout << s.search(4) << "\n";

    return 0;
}