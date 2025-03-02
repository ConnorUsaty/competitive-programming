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
    void traverse(TreeNode* t, int& ans, int curr){
        curr <<= 1;
        curr += t->val;
        
        if(t->left == nullptr && t->right == nullptr){
            ans += curr;
        }
        else{
            if(t->left) traverse(t->left, ans, curr);
            if(t->right) traverse(t->right, ans, curr);
        }
    }
    
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        traverse(root, ans, 0);
        return ans;
    }
};

// to build up a binary number * 2 or left shift one each time before adding next digit
// similar to how we * 10 each time before adding next digit when building up a normal (base 10) number