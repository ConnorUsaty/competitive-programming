class UnionFind{
private:
    vector<int> parent_;
    vector<int> size_;

public:
    UnionFind(int n) : size_(n,1), parent_(n){
        for(int i=0; i<n; ++i){
            parent_[i] = i;
        }
    }

    int find(int x){
        return parent_[x] = (parent_[x]==x ? x : find(parent_[x]));
    }

    int merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return 0; // already merged

        if(size_[x]<size_[y]) swap(x,y);
        size_[x] += size_[y];
        parent_[y] = x;
        return 1; // performed merge, one less province
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=(int)isConnected.size();
        UnionFind uf(n);

        int ans=n;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(j!=i && isConnected[i][j]){
                    ans -= uf.merge(i,j);
                }
            }
        }
        return ans;
    }
};

// question is about number of connected components
// UnionFind is the best way to track connected components
// O(logn) time for uf.find() and uf.merge()
// always use path compression and merge the smaller component onto the bigger one