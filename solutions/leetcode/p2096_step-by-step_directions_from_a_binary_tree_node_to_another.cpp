/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool dfs(TreeNode* t, int level, int start, int end, std::string& path, std::string& end_path, std::array<int,2>& levels) {
        if(t == nullptr) return false;

        path.push_back('L');
        bool l = dfs(t->left, level+1, start, end, path, end_path, levels);
        path.back() = 'R';
        bool r = dfs(t->right, level+1, start, end, path, end_path, levels);
        path.pop_back();
        bool p = t->val == start || t->val == end;

        if(l+r+p >= 2 && levels[0] == -1) levels[0] = level;
        if(t->val == start) levels[1] = level;
        if(t->val == end) end_path = path;

        return l || r || p;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        std::string path;
        std::string dest_path;
        std::array<int, 2> levels;
        std::fill(levels.begin(), levels.end(), -1);

        dfs(root, 0, startValue, destValue, path, dest_path, levels);

        std::string ans(levels[1]-levels[0], 'U');
        ans += dest_path.substr(levels[0], dest_path.size()-levels[0]);
        return ans;
    }
};

// basically any solution to this will be O(n) time and space due to DFS / BFS
// however this solution only maintains the exact info we need for each part of the solution (lca, start, end)
// the lca will always be a part of the path from a node s to e in a tree
// instead of backtracking to get level diff of start and lca we can just store the level of both
// instead of backtracking to build path from end to LCA we can just take the substr of the path from root to end and cut out the part before lca level
