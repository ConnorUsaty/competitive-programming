class Solution {
private:
    struct UnionFind {
    private:
        unordered_map<int,int> parent_{};
        unordered_map<int,int> size_{};
        int components_{0};

    public:
        UnionFind() = default;

        int find(int x) {
            if(parent_.find(x) == parent_.end()) {
                size_.insert({x, 1});
                parent_.insert({x, x});
                components_++;
                return x;
            }
            return parent_[x] = (parent_[x] == x ? x : find(parent_[x]));
        }

        void merge(int x, int y) {
            x = find(x);
            y = find(y);
            if(x == y) return;

            if(size_[x] < size_[y]) swap(x, y);
            size_[x] += size_[y];
            parent_[y] = x;
            components_--;
        }

        int get_components() const noexcept {
            return components_;
        }
    };

public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf;
        for(auto& stone : stones) {
            uf.merge(stone[0], ~stone[1]); // connect row and col
        }
        return stones.size() - uf.get_components();
    }
};

// for any question where the answer depends on number of connected components in an UNDIRECTED graph, we should consider union find
// UnionFind with correct path compression and size optimizations is O(n * a(n)), where a is the inverse Ackermann function (almost constant)
// we do not need an explicit adj list for UF, i.e. here we just connect the row to the column for each stone
// we also do not need N the number of nodes to do UF, as we see here we use maps instead of vectors to deal with this
// we SHOULD use vectors when we know n though to avoid hashing and collision overhead
// we need to avoid collisions for row and col so we do ~col to get -(col+1) which guarentees no collisions since row >= 0
// there are many other ways to avoid collisions such as odds / evens for rows / cols