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
    bool traverse(TreeNode* t, int v){
        if(!t){
            return false;
        }

        v -= t->val;

        if(!t->left && !t->right){
            return v == 0;
        }

        return (traverse(t->left, v) || traverse(t->right, v));
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return traverse(root, targetSum);
    }
};

// always check base case of curr node being null
// make helper functions private
// recursively traverse tree