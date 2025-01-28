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


void test(const std::vector<std::string> operations, const std::vector<int> values, const std::vector<std::vector<int>> exp_vals) {

    int test_cases = (int)operations.size();
    int passes = 0;

    SparseSet test_set(25);

    for(int i=0; i<test_cases; ++i){
        std::string op = operations[i];
        int val = values[i];
        std::vector<int> exp = exp_vals[i];

        if(op == "insert"){
            test_set.insert(val);
            if(test_set.iterate() == exp) passes++;
            else std::cout << "Test " << i << " failed." << "\n";
        }
        else if (op == "remove"){
            test_set.remove(val);
            if(test_set.iterate() == exp) passes++;
            else std::cout << "Test " << i << " failed." << "\n";
        }
        else if (op == "clear"){
            test_set.clear();
            if(test_set.iterate() == exp) passes++;
            else std::cout << "Test " << i << " failed." << "\n";
        }
        else if (op == "search"){
            bool res = test_set.search(val);
            if(res == exp[0]) passes++;
            else std::cout << "Test " << i << " failed." << "\n";
        }
    }
    std::cout << "Passed " << passes << "/" << test_cases << " test cases.\n";
}



int main() {
    std::vector<std::string> operations = {"insert","insert","insert","remove","insert","clear","search","insert","search"};
    std::vector<int> values = {1,2,1,1,3,-1,5,5,5};
    std::vector<std::vector<int>> exp_vals = {{1},{1,2},{1,2},{2},{2,3},{},{0},{5},{0}};

    test(operations, values, exp_vals);

    return 0;
}

// should _capacity be c+1? Is it supposed to be insertable up to c (inclusive or exclusive) ??