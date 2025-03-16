/*
File contains implementation of a segment tree

Segment trees are used to query and update array intervals in O(logn) time, using O(n) space (max = 4*n)
Can process min, max, sum, prod, etc. queries

More complex and robust version of BIT (Binary Indexed Tree) (Fenwick Tree) which can only process sum queries, but also supports O(logn) queries and updates of array intervals
*/

#include <vector>
#include <functional>
#include <climits>
#include <iostream>

using namespace std;

class SegmentTree{
public:
    SegmentTree(vector<int> a, function<int(int,int)> func) : t(4*a.size(), INT_MIN) {
        func_ = func;
        build(a, 1, 0, (int)a.size()-1);
    }

    // v = index in tree, tl = left bound of t[v], tr = right bound of t[v], l = left bound of query, r = right bound of query
    int query(int v, int tl, int tr, int l, int r) {
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;

        if(l>min(r,tm)){
            return query(v*2+1, tm+1, tr, max(l, tm+1), r);
        }
        else if(max(l, tm+1) > r){
            return query(v*2, tl, tm, l, min(r, tm));
        }
        return func_(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = func_(t[v*2], t[v*2+1]);
        }
    }

private:
    vector<int> t;
    function<int(int,int)> func_;

    // a = orig. arr., v = index in tree, tl = left bound in a, tr = right bound in a
    void build(vector<int> a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = func_(t[v*2], t[v*2+1]);
        }
    }
};

int main(){
    vector<int> a = {1, 3, 3, 8, -7};

    function<int(int,int)> mx = [](int a, int b){
        if (a>b) return a;
        return b;
    };
    SegmentTree st(a, mx);

    cout << st.query(1, 0, (int)a.size()-1,  0, (int)a.size()-1) << "\n";
    cout << st.query(1, 0, (int)a.size()-1,  0, 0) << "\n";
    cout << st.query(1, 0, (int)a.size()-1,  1, 3) << "\n";
    cout << st.query(1, 0, (int)a.size()-1,  1, 2) << "\n";
    cout << st.query(1, 0, (int)a.size()-1,  3, 3) << "\n";
    cout << st.query(1, 0, (int)a.size()-1,  4, 4) << "\n";
    
    st.update(1, 0, (int)a.size()-1, 3, -1);
    cout << "\n";
    
    cout << st.query(1, 0, (int)a.size()-1,  0, (int)a.size()-1) << "\n";
    cout << st.query(1, 0, (int)a.size()-1,  1, 3) << "\n";
    cout << st.query(1, 0, (int)a.size()-1,  1, 2) << "\n";
    cout << st.query(1, 0, (int)a.size()-1,  3, 3) << "\n";
    cout << "\n" << "\n";


    function<int(int,int)> sm = [](int a, int b){
        return a+b;
    };
    SegmentTree st_sm(a, sm);

    cout << st_sm.query(1, 0, (int)a.size()-1,  0, (int)a.size()-1) << "\n";
    cout << st_sm.query(1, 0, (int)a.size()-1,  0, 0) << "\n";
    cout << st_sm.query(1, 0, (int)a.size()-1,  1, 3) << "\n";
    cout << st_sm.query(1, 0, (int)a.size()-1,  1, 2) << "\n";
    cout << st_sm.query(1, 0, (int)a.size()-1,  3, 3) << "\n";
    cout << st_sm.query(1, 0, (int)a.size()-1,  4, 4) << "\n";
    
    st_sm.update(1, 0, (int)a.size()-1, 3, -1);
    cout << "\n";
    
    cout << st_sm.query(1, 0, (int)a.size()-1,  0, (int)a.size()-1) << "\n";
    cout << st_sm.query(1, 0, (int)a.size()-1,  1, 3) << "\n";
    cout << st_sm.query(1, 0, (int)a.size()-1,  1, 2) << "\n";
    cout << st_sm.query(1, 0, (int)a.size()-1,  3, 3) << "\n";

    return 0;
}
