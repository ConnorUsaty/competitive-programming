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
    bool checkTree(TreeNode* t, TreeNode* s){
        if(t==nullptr && s==nullptr) return true;
        if(t==nullptr || s==nullptr || t->val!=s-> val) return false;
        
        return (checkTree(t->left,s->left) && checkTree(t->right,s->right));
    }
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(root->val==subRoot->val && checkTree(root, subRoot)) return true;
        
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)); 
    }
};

// traverse down original tree checking trees at each potential match
// do NOT traverse substree except for checking