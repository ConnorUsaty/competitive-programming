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
    void traverse(TreeNode* t, int& curr){
        if(t == nullptr) return;

        traverse(t->right, curr);
        curr += t->val;
        t->val = curr;
        traverse(t->left, curr);
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        int curr = 0;
        traverse(root, curr);
        return root;
    }
};

// can traverse tree in reverse order; i.e. right, parent, left
// when parent processed, increment curr, then set parent->val
