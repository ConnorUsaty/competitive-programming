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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        
        if(p && q){
            if(p->val != q->val) return false;
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }
        
        return false;
    }
};

// always make sure that ptr is not null before accessing member variables
// i.e. if !p and we try p->val we will get an access error
// good base case for traversing trees is always checking if node(s) null