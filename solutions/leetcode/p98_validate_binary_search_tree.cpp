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

typedef long long ll;

class Solution {
private:
    bool inorder(TreeNode* t, ll& mx){
        if(t == nullptr) return true;

        if(!inorder(t->left, mx)) return false;
        if(t->val <= mx) return false;
        mx = t->val;
        if(!inorder(t->right, mx)) return false;

        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        ll mx = LLONG_MIN;
        return inorder(root, mx);
    }
};
 
 // inorder traversal should give us sorted order
 // just perform an inorder traversal and check that each node > last node

// O(n) time -> visiting all nodes, O(h) space -> recursive call stack

// an inorder traversal of a BST will provide the nodes in a sorted order
// therefore to validate a BST we can perform an inorder traversal and ensure that the nodes we are visiting are strictly increasing

// inorder traversal, ensure always increasing ?
// recursively checking each level doesnt work because value on other side of tree could be incorrect