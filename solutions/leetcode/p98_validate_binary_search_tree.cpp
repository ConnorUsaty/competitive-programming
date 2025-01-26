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
    void traverse(TreeNode* t, long long& last, bool& valid){
        if(!t || !valid) return;

        traverse(t->left, last, valid);
        if(t->val <= last){
            valid = false;
        } else {
            last = t->val;
        }
        traverse(t->right, last, valid);
    }

public:
    bool isValidBST(TreeNode* root) {
        long long last = LLONG_MIN;
        bool valid = true;
        traverse(root, last, valid);
        return valid;
    }
};

// O(n) time -> visiting all nodes, O(h) space -> recursive call stack

// an inorder traversal of a BST will provide the nodes in a sorted order
// therefore to validate a BST we can perform an inorder traversal and ensure that the nodes we are visiting are strictly increasing

// inorder traversal, ensure always increasing ?
// recursively checking each level doesnt work because value on other side of tree could be incorrect