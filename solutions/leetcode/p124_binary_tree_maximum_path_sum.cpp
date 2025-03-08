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
    int ans;

    int traverse(TreeNode* t){
        if(t == nullptr) return 0;

        int left = max(traverse(t->left), 0);
        int right = max(traverse(t->right), 0);
        ans = max(ans, left+right+t->val);

        return max(left+t->val, right+t->val);
    }

public:
    int maxPathSum(TreeNode* root) {
        ans = -1001;
        traverse(root);
        return ans;
    }
};

// kadanes algorithm but on a tree
// traverse keep track of curr sum, at each node set ans = max(ans, curr);
// if curr ever < 0, reset AFTER setting ans