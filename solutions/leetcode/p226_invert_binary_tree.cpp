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
    void helper(TreeNode* t){
        if(!t) return;

        TreeNode* temp = t->left;
        t->left = t->right;
        t->right = temp;
        helper(t->left);
        helper(t->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};