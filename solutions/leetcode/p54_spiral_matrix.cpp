class Solution {
private:
    void dfs(int i, int j, int d, vector<int>& ans, vector<vector<int>>& m){
        if(i>=0 && i<m.size() && j>=0 && j<m[0].size() && m[i][j]!=101){
            ans.push_back(m[i][j]);
            m[i][j]=101;
            if(d==3) dfs(i-1, j, 3, ans, m);

            dfs(i, j+1, 0, ans, m);
            dfs(i+1, j, 1, ans, m);
            dfs(i, j-1, 2, ans, m);
            dfs(i-1, j, 3, ans, m);
        }
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        dfs(0, 0, 0, ans, matrix);
        return ans;
    }
};

// path follows simple dfs pattern BUT you have to ensure you continue up instead of immediately turning right when going up
// O(n) time, O(1) space not including ans vector