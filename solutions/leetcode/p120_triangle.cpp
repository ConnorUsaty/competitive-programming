class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle[triangle.size()-1].size();
        vector<vector<int>> dp(triangle.size(), vector<int>(m, 0));
        dp[0][0] = triangle[0][0];

        for(int i=1; i<triangle.size(); ++i){
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            for(int j=1; j<triangle[i].size(); ++j){
                if(j+1<triangle[i].size()){
                    dp[i][j] = min(dp[i-1][j-1]+triangle[i][j], dp[i-1][j]+triangle[i][j]);
                } else {
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
            }
        }

        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};

// need multiple rows in dp since we access [i-1][j-1]
// need to use *min_element as the best path could end on any index not necessarily the last one
// O(n) time where n = num of elements in triangle
// O(l^2) space where l = num of levels in triangle -> could probably be optimized by only keeping track of curr and prev rows for O(l) space