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
    void traverse(TreeNode* t, vector<int>& sequence){
        if(!t) return;
        
        if(!t->left && !t->right) {
            sequence.push_back(t->val);
            return;
        }

        traverse(t->left, sequence);
        traverse(t->right, sequence);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf_sequence1, leaf_sequence2;

        traverse(root1, leaf_sequence1);
        traverse(root2, leaf_sequence2);

        return leaf_sequence1==leaf_sequence2;
    }
};


// traverse trees and track values of leafs
// always remember your base cases when using recursion
// -> acts as a derefernce, use instead of . when dealing with obj ptrs