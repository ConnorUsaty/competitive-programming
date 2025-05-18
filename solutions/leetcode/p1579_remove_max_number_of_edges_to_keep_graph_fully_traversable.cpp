class UnionFind{
private:
    vector<int> parent_;
    vector<int> size_;

public:
    UnionFind(int n) : size_(n,1), parent_(n,0) {
        for(int i=0; i<n; ++i){
            parent_[i]=i;
        }
    }

    int find(int x){
        return parent_[x] = (parent_[x]==x ? x : find(parent_[x]));
    }

    int merge(int i, int j){
        i = find(i);
        j = find(j);
        if(i == j) return 1;

        if(size_[i]<size_[j]) swap(i,j); // ensure [i] is bigger
        size_[i] += size_[j];
        parent_[j] = i;
        return 0;
    }

    int get_size(int i){
        i = find(i);
        return size_[i];
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind A(n);
        UnionFind B(n);

        int ans=0;
        for(auto& e : edges){
            int t = e[0];
            int u = e[1]-1; // make 0-indexed
            int v = e[2]-1; // make 0-indexed
            if(t==3){
                ans += (A.merge(u,v) | B.merge(u,v));
            }
        }

        for(auto& e : edges){
            int t = e[0];
            int u = e[1]-1; // make 0-indexed
            int v = e[2]-1; // make 0-indexed
            if(t==1){
                ans += A.merge(u,v);
            }
            else if(t==2){
                ans += B.merge(u,v);
            }
        }

        // both sizes should = n if fully connected
        int asize = A.get_size(0), bsize = B.get_size(0);
        return (asize==n && bsize==n ? ans : -1);
    }
};

// Union Find with seperate UF objs for alice and bob
// start at arbitrary node 1
// traverse all edges from node and:
// if edge unvisited:
// mark edge as visited so we dont redo from another node
// if edge type 1 union those 2 nodes for alice, if parent already the same ans++
// if edge type 2 union those 2 nodes for bob, if parent already the same ans++
// if edge type 3 union those 2 nodes for alice AND bob, if parent already the same ans++
// repeat for all nodes
// return ans


// UnionFind is a disjoint set implementation that is very useful for keeping track of connected components within graphs
// to optimize UnionFind utilize path compression during find() and always merge the smaller set onto the bigger one during merge()
// time complexity for UF.find() and UF.merge() is O(logn)
// time complexity for UF init. is O(n)