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
    bool traverse(TreeNode* t, int curr, int limit){
        if(!t->left && !t->right) return (curr+t->val >= limit);

        curr += t->val;
        bool l = (t->left && traverse(t->left, curr, limit));
        bool r = (t->right && traverse(t->right, curr, limit));
        if(!l) t->left = nullptr;
        if(!r) t->right = nullptr;

        return (l || r);
    }

public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(!traverse(root,0,limit)) return nullptr;
        return root;
    }
};
    
// build up path sum as we move down
// remove invalid nodes as we move back up
// if no paths were valid, return nullptr
// else return root (which will be root of new tree since we remove invalid nodes on way back up)