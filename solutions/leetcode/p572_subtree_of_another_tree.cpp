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
    bool treeMatch(TreeNode* t, TreeNode* s){
        if(!t && !s) return true;
        if(!t || !s) return false;

        if(t->val == s->val){
            return (treeMatch(t->left, s->left) && treeMatch(t->right, s->right));
        }
        return false;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (treeMatch(root, subRoot)) return true;
        if (!root) return false;
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};


// at each node of tree, check if that node contains the subtree
// traverse down original tree while keeping subRoot at top of subtree
// only move subRoot ptr down tree when performing a check and always keep the reference to original subRoot for check at next node