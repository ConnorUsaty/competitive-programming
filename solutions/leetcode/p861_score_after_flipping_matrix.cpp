class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = (int)grid.size(), m = (int)grid[0].size();
        vector<int> cnt(m,0); // [col] = cnt of 1s in col

        for(int i=0; i<n; ++i){
            if(!grid[i][0]){
                for(int j=0; j<m; ++j){
                    grid[i][j] ^= 1;
                }
            }
            for(int j=1; j<m; ++j){
                if(grid[i][j]) cnt[j]++;
            }
        }

        int ans = 0, shift = 1;
        for(int j=m-1; j>0; --j){
            int ones = max(cnt[j], n-cnt[j]);
            ans += (ones * shift);
            shift <<= 1;
        }
        ans += (n * shift);
        return ans;
    }
};

// can always make first col into all 1s
// BUT can make it into all 1s either by first going to 0 and flipping col
// OR by flipping each row that has it as 0 to 1
// no matter which method we choose after applying the greedy col flips we will get the same res

// then we simply go across the remaining rows and flip if cnt of 0 > cnt of 1