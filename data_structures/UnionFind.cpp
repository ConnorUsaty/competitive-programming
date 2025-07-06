/* 
Default UnionFind template. Can modify uf.merge() to return a value indicating if merge was required. uf.find() and uf.merge() are O(logn) time. UnionFind() ctor is O(n) time and space.

UnionFind is the best way to track connected components in an UNDIRECTED graph.
*/

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

    void merge(int x, int y){
        x = find(x);
        y = find(y);

        if(x == y) return;
        if(size_[x]<size_[y]) swap(x,y);
        size_[x] += size_[y];
        parent_[y] = x;
    }
};
