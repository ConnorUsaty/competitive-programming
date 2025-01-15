#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// puts greatest first
// custom comparator using "functor" (function object)
struct Comp {
    bool operator()(vector<int>& a, vector<int>& b){
        return (a[0]>b[0]) || (a[0]==b[0] && a[1]>b[1]);
    }
};

int main(){
    vector<vector<int>> a = {{2,0},{0,0},{0,1},{1,0},{1,1}};
    sort(a.begin(), a.end(), Comp());

    for(auto p : a){
        cout << p[0] << ' ' << p[1] << "\n";
    }

    return 0;
}

