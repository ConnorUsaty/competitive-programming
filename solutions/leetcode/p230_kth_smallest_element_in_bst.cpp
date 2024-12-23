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
    int ans=0;

    void traverse(TreeNode* t, int &k){
        if(!t || !k) return;

        if(t->left) traverse(t->left, k);
        if(--k == 0){
            ans = t->val;
        }
        if(t->right) traverse(t->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return ans;
    }
};


// in order traversal of BST gives sorted order of all elements