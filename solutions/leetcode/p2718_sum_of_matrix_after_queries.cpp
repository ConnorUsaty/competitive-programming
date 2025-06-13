class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans = 0;
        vector<vector<int>> used(2, vector<int>(n, 0));
        int cnt[2] = {n, n};

        for(int i=(int)queries.size()-1; i>=0; --i){
            auto const & q = queries[i];
            if(used[q[0]][q[1]]) continue;

            ans += 1LL*q[2]*cnt[q[0]^1];
            cnt[q[0]]--;
            used[q[0]][q[1]] = 1;
        }
        return ans;
    }
};

// start from back
// ans += query[val] * cnt[type^1]
// cnt[0] = rows unset
// cnt[1] = cols unset

// when we apply a col query we check if this col has alr been set
// if yes skip query
// if no ans += query[val] * cnt[0]
//      also need to cnt[1]--; and mark col as set