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
    void traverse(TreeNode* t, int& k, int& ans){
        if(t == nullptr || ans != -1) return;

        traverse(t->left, k, ans);
        if(--k == 0) ans = t->val;
        else traverse(t->right, k, ans);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        traverse(root, k, ans);
        return ans;
    }
};

// inorder traversal of BST gives sorted order of elements
// inorder traversal, increment count of nodes passed at parent step by decrementing k