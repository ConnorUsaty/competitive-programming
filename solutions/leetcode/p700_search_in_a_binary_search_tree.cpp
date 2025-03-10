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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(root->val < val){
                root = root->right;
            }
            else if (root->val > val) {
                root = root->left;
            }
            else {
                return root;
            }
        }
        return root;
    }
};

// traverse / binary search down tree until val is found or curr node is null (val not in BST)