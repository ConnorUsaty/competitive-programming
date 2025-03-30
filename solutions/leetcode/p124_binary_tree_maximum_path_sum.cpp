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
    int dfs(TreeNode* t, int& ans){
        if(t == nullptr) return 0;

        int left = dfs(t->left, ans);
        int right = dfs(t->right, ans);
        
        ans = max(ans, left+right+t->val);
        return max(0, max(left,right) + t->val);
    }

public:
    int maxPathSum(TreeNode* root) {
        int ans = -1001;
        dfs(root, ans);
        return ans;
    }
};

// kadanes algorithm but on a tree
// traverse keep track of curr sum, at each node set ans = max(ans, curr);
// if curr ever < 0, reset AFTER setting ans
