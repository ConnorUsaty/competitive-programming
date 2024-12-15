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
    int findMax(TreeNode* t, int h){
        if(!t){
            return h;
        }

        return max(findMax(t->left, h+1), findMax(t->right, h+1));
    }
    
public:
    int maxDepth(TreeNode* root) {
        return findMax(root, 0);
    }
};