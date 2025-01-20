/*

Bitmap buddy implementation practice v2

Tree where each node is 1 iff all nodes below are 1, 0 o.w.

Implement:
set_bit(offset, length) -> sets all bits from offset to offset+length
clear_bit(offset, length) -> clears all bits from offset to offset+length

*/

#include <vector>
#include <algorithm>

class BitMapBuddy {
private:
    std::vector<int> _bmb;

    void set_down(int i) {
        // Ensure all bits below are set -> needs to be recursive

        _bmb[i] = 1;
        int left_child = 2*i+1;
        int right_child = 2*i+2;
        if(left_child<(int)_bmb.size() && _bmb[left_child]==0) set_down(left_child);
        if(right_child<(int)_bmb.size() && _bmb[right_child]==0) set_down(right_child);
    }

    void set_up(int i) {
        // Ensure parent bit is set if this caused both children to be set
        // Parent might have 0, 1, or 2 children -> Accounted for with tenary operator
        // If it only has a left child and left is set should it be set ??
        // if above have to do 3 if statment instead of tenary operator

        // edge case of only having a left child
        if(2*i+1<_bmb.size() && _bmb[2*i+1] && 2*i+2>=_bmb.size()) {
            _bmb[i] = 1;
            i = (i-1) / 2;
        }

        while(!_bmb[i]) {
            int left_child = (2*i+1 < _bmb.size()) ? _bmb[2*i+1] : 0;
            int right_child = (2*i+2 < _bmb.size()) ? _bmb[2*i+2] : 0;
            if (left_child && right_child) {
                _bmb[i] = 1;
                i = (i-1) / 2;
            }
            else {
                break;
            }
        }
    }

    void clear_up(int i) {
        while(_bmb[i]){
            _bmb[i] = 0;
            i = (i-1) / 2;
        }
    }

    void clear_down(int i) {
        int left_child = (2*i+1 < _bmb.size()) ? _bmb[2*i+1] : 0;
        int right_child = (2*i+2 < _bmb.size()) ? _bmb[2*i+2] : 0;
        while (left_child && right_child) {
            _bmb[2*i+1] = 0;
            i = 2*i+1;
            left_child = (2*i+1 < _bmb.size()) ? _bmb[2*i+1] : 0;
            right_child = (2*i+2 < _bmb.size()) ? _bmb[2*i+2] : 0;
        }
        // for case with singular left child that is leaf, and right child is null
        if(left_child && 2*i+2>=(int)_bmb.size()) {
            _bmb[2*i+1] = 0;
        }
    }

public:
    BitMapBuddy(std::vector<int> bmb) : _bmb(bmb) {};

    void set_bit(int offset, int length) {
        int upper_bound = std::min((int)_bmb.size(), offset+length);
        for(int i=offset; i<upper_bound; ++i){
            if(_bmb[i] == 0){
                set_down(i); // start at curr
                set_up(i/2); // start at parent
            }
        }
    }

    void clear_bit(int offset, int length) {
        int upper_bound = std::min((int)_bmb.size(), offset+length);
        for(int i=offset; i<upper_bound; ++i){
            if(_bmb[i] == 1){
                clear_up(i); // start at curr
                clear_down(i); // start at curr
            }
        }
    }
};
