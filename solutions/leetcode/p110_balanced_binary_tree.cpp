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
    void solve(TreeNode* t, bool& ans, int& h) {
        if(!t || !ans) {
            return;
        }
        int l=0, r=0;
        solve(t->left,ans,l);
        solve(t->right,ans,r);

        h = max(l,r)+1;
        if(abs(l-r)>1){
            ans = false;
        }
    }

public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int h = 0;
        solve(root,ans,h);
        return ans;
    }
};

// can pass address of h and ans so that they are passed by reference and values are updated without returning
// need to init variables before passing when passing by reference