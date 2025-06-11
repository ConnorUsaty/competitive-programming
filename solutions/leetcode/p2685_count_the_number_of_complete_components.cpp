class UnionFind {
private:
    vector<int> nodes_;
    vector<int> edges_;
    vector<int> parent_;

public:
    UnionFind(int n) : nodes_(n, 1), edges_(n, 0), parent_(n) {
        for(int i=0; i<n; ++i){
            parent_[i] = i;
        }
    }

    int find(int x){
        return parent_[x] = (parent_[x] == x ? x : find(parent_[x]));
    }

    void merge(int x, int y){
        x = find(x);
        y = find(y);

        if(x==y){
            edges_[x]++;
            return;
        }

        if(nodes_[x]<nodes_[y]) swap(x,y);
        nodes_[x] += nodes_[y];
        edges_[x] += edges_[y]+1;
        parent_[y] = x;
    }

    int query(){
        int n = (int)parent_.size(), res=0;
        vector<int> used(n, 0);
        for(int i=0; i<n; ++i){
            int x = find(i);
            if(nodes_[x]==1 || edges_[x] == (nodes_[x] * (nodes_[x]-1))/2){
                if(!used[x]){
                    used[x] = 1;
                    res++;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(auto const & e : edges){
            uf.merge(e[0], e[1]);
        }
        return uf.query();
    }
};

// since there is no repeated edges just track |E| and |V| for all connected components
// if |E| == (|V|*(|V|-1)) / 2 OR |V| == 1, then +1 for that component, else nothing
