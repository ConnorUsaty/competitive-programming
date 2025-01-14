/*

Bitmap buddy implementation practice

Tree where each node is 1 iff all nodes below are 1, 0 o.w.

Implement:
set_bit(offset, length)
clear_bit(offset, length)

Have to ensure all below nodes are properly set when setting, ALSO have to check if any parents above must now be set
Can do this by iteratively traversing down the tree with the fact that children are 2*i + 1 or 2, just make sure to have base case of _m[i] == 0 and i out of index range

Have to ensure that all parent nodes are properly cleared when clearing bit, ALSO have to ensure at least one child is cleared (Always do left (Design choice))
Can do this by iteratively traversing tree with fact that parent = floor( (i-1) / 2)

*/

#include <vector>
#include <algorithm>
#include <iostream>


class bitmap_buddy{
private:
    std::vector<int> _m;

    void set_up(int i){
        int l = (2*i+1<_m.size()) ? _m[2*i+1] : 0;
        int r = (2*i+2<_m.size()) ? _m[2*i+2] : 0;
        while(l && r && !_m[i]) {
            _m[i] = 1;
            i = (i-1) / 2;
            l = (2*i+1<_m.size()) ? _m[2*i+1] : 0;
            r = (2*i+2<_m.size()) ? _m[2*i+2] : 0;
        }
    }

    void set_down(int i){
        int l = i*2+1;
        while(l < _m.size() && !_m[l]){
            _m[l] = 1;
            l = l*2+1;
        }
        int r = i*2+2;
        while(r < _m.size() && !_m[r]){
            _m[r] = 1;
            r = r*2+2;
        }
    }

    void clear_up(int i){
        while(_m[i]){
            _m[i]=0;
            i = (i-1) / 2;
        }
    }

    void clear_down(int i){
        int l = (2*i+1<_m.size()) ? _m[2*i+1] : 0;
        int r = (2*i+2<_m.size()) ? _m[2*i+2] : 0;
        while(l && r){
            _m[2*i+1] = 0;
            i = 2*i+1;
            l = (2*i+1<_m.size()) ? _m[2*i+1] : 0;
            r = (2*i+2<_m.size()) ? _m[2*i+2] : 0;
        }
    }

public:
    bitmap_buddy(std::vector<int> m) : _m(m) {};

    void set_bit(int offset, int length) {
        int upper_bound = std::min((int)_m.size(), offset+length);
        for(int i=offset; i<upper_bound; ++i){
            if(_m[i] == 0){
                _m[i]=1;
                set_down(i);
                set_up((i-1)/2);
            }
        }
    }

    void clear_bit(int offset, int length) {
        int upper_bound = std::min((int)_m.size(), offset+length);
        for(int i=offset; i<upper_bound; ++i){
            if(_m[i]){
                clear_up(i);
                clear_down(i);
            }
        }
    }

    void printBMB(){
        for(auto n : _m) std::cout << n << ' ';
        std::cout << "\n";
    }
};

int main(){
    std::vector<int> a = {0,0,1,1,0,1,1,1,1,1,0,1};
    bitmap_buddy b(a);

    b.printBMB();

    b.set_bit(4,1);

    b.printBMB();

    b.clear_bit(0,1);

    b.printBMB();

    b.set_bit(0,1);

    b.printBMB();

    b.clear_bit(4,100);

    b.printBMB();

    // should clear bits 1 through 5 1+5-1 = 5
    // b.clear_bit(1,5);

    // b.printBMB();

    // b.clear_bit(1,100);

    // b.printBMB();

    // b.set_bit(3,3);

    // b.printBMB();

    return 0;
}
