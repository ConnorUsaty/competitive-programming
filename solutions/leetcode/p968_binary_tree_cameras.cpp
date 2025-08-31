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
    int traverse(TreeNode* t, int& ans, bool has_parent) {
        if(t == nullptr) return 1;

        int l = traverse(t->left, ans, true);
        int r = traverse(t->right, ans, true);
        if(l==0 || r==0) {
            // need to place here, child not covered
            ans++;
            return 2;
        }
        else if(!has_parent && (l==1 && r==1)){
            ans++;
            return 2;
        }
        else {
            // both children are covered
            return max(l,r)-1;
        }
    }

public:
    int minCameraCover(TreeNode* root) {
        if(!root->left && !root->right) return 1;
        // post order traversal, place every other level starting at leaf + 1
        int ans = 0;
        traverse(root, ans, false);
        return ans;
    }
};

// edge case where we can afford to place them with 2 empty levels
// should always place as high as possible