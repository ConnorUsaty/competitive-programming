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
    int height(TreeNode* t, bool& ans){
        if(!ans || t==nullptr) return 0;

        int lh = height(t->left, ans);
        int rh = height(t->right, ans);

        if(max(lh,rh) - min(lh,rh) > 1){
            ans = false;
        }

        return max(lh,rh) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int h = height(root, ans);
        return ans;
    }
};