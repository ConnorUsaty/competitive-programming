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
    int traverse(TreeNode* t, int largest, int good){
        if(!t) return good;

        largest = max(largest, t->val);
        int l = traverse(t->left, largest, good);
        int r = traverse(t->right, largest, good);

        if(t->val >= largest) return l+r+1;
        else return l+r;
    }

public:
    int goodNodes(TreeNode* root) {
        return traverse(root, root->val, 0);
    }
};

// post order traversal, similar to getting height in traversal and implementation
// except we have to check for certain condition