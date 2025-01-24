/*
Practicing implementation of SparseSet
*/

#include <iostream>
#include <vector>
#include <functional>

class SparseSet {
private:
    int _capacity;
    int _size;
    int _ts;
    std::vector<int> _vals;
    std::vector<int> _timestamps;
    std::vector<int> _idx;

public:
    SparseSet(int c) : _capacity(c), _size(0), _ts(1), _vals(c), _timestamps(c), _idx(c) {};

    void insert(int v) {
        if (v<0 || v>=_capacity) return;

        if (_ts != _timestamps[v]) {
            _timestamps[v] = _ts;
            _idx[v] = _size;
            _vals[_size] = v;
            _size++;
        }
    }

    void remove(int v) {
        if (v<0 || v>=_capacity) return;

        if (_ts == _timestamps[v]) {
            _timestamps[v] = 0;
            std::swap(_vals[_idx[v]], _vals[_size-1]);
            _size--;
        }
    }

    bool search(int v) {
        return _ts == _timestamps[v];
    }

    void clear() {
        _ts++;
        if(_ts == 0) _ts++; // to account for overflow, since we use _timestamps[i] = 0 for default
        _size = 0;
    }

    std::vector<int> iterate() {
        return std::vector<int>(_vals.begin(), _vals.begin()+_size);
    }

    void printVals() {
        std::vector<int> curr_vals = iterate();
        if(curr_vals.size() == 0) {
            std::cout << "EMPTY\n";
            return;
        }
        
        for (const int& v : curr_vals) std::cout << v << ' ';
        std::cout << "\n";
    }
};

int main() {
    SparseSet s(14);
    s.printVals();

    s.insert(1);
    s.insert(1);
    s.insert(4);
    s.insert(11);
    s.insert(12);
    s.insert(1);
    s.insert(13);
    s.insert(15);

    s.printVals();

    s.remove(31);
    s.remove(13);
    s.remove(1);
    s.remove(4);
    s.remove(1);

    s.printVals();

    s.clear();

    s.printVals();

    s.insert(1);
    s.insert(1);
    s.insert(4);
    s.insert(11);
    s.insert(12);
    s.insert(1);
    s.insert(13);
    s.insert(15);

    s.printVals();

    s.remove(31);
    s.remove(13);
    s.remove(1);
    s.remove(4);
    s.remove(1);

    s.printVals();

    std::cout << "Searching for 1: " << s.search(1) << "\n";
    std::cout << "Searching for 1: " << s.search(1) << "\n";
    std::cout << "Searching for 11: " << s.search(11) << "\n";
    std::cout << "Searching for 12: " << s.search(12) << "\n";
    std::cout << "Searching for 14: " << s.search(14) << "\n";
    std::cout << "Searching for 14: " << s.search(14) << "\n";

    s.insert(14);
    s.insert(0);
    s.insert(14);

    std::cout << "Searching for 14: " << s.search(14) << "\n";
    std::cout << "Searching for 0: " << s.search(0) << "\n";

    s.printVals();


    return 0;
}

// should _capacity be c+1? Is it supposed to be insertable up to c (inclusive or exclusive) ??