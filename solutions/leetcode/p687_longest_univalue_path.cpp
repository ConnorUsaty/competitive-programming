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
    int inorder(TreeNode* t, int& ans){
        if(t == nullptr) return 0;

        // query left and right
        int left = 1, right = 1;
        if(t->left){
            left = inorder(t->left, ans) + ((t->left->val==t->val)?1:0);
        }
        if(t->right){
            right = inorder(t->right, ans) + ((t->right->val==t->val)?1:0);
        }

        // update ans
        if(t->left && t->right && t->left->val==t->right->val && t->left->val==t->val){
            ans = max(ans, left+right-1);
        } else {
            ans = max(ans, max(left,right));
        }

        // return longest path that can connect upwards
        // either right or left iff curr val = child vals else curr val
        int curr = 1; // curr node only
        if(t->left && t->left->val==t->val){
            curr = left;
        }
        if(t->right && t->right->val==t->val){
            curr = max(curr, right);
        }
        return curr;
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        
        int ans = 0;
        inorder(root, ans);
        return ans-1;
    }
};

// O(n) time, O(1) space
// can perform an inorder traversal building up paths from the bottom
// this allows us to build across, i.e. connect left to right paths
// when passing a value upwards in the tree we need to make sure it is the larger of left and right NOT left + right
// when updating ans we can connect left and right if left val == right val == parent val
// make sure to handle edge cases like no root or only root