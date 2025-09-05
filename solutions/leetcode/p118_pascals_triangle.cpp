class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        ans[0] = {1};
        for(size_t row = 1; row < numRows; ++row) {
            ans[row].reserve(row+1);
            ans[row].push_back(1);
            for(size_t col = 1; col < row; ++col) {
                ans[row].push_back(ans[row-1][col-1] + ans[row-1][col]);
            }
            ans[row].push_back(1);
        }
        return ans;
    }
};

// 1 <= numRows <= 30