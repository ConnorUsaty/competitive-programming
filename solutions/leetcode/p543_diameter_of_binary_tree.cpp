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
    int getHeight(TreeNode* t, int h, int& d){
        if(!t){
            return h;
        }

        int lh = getHeight(t->left, h, d);
        int rh = getHeight(t->right, h, d);

        d = max(d, lh+rh);
        return max(lh,rh)+1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        getHeight(root, 0, d);
        return d;
    }
};

// at each node get left and right height
// update d to be max(d, lh+rh)
// return max(lh+rh)+1

// can all be done in one function using int& d to update d, and returning h to get the heights
// need seperate h and d variables when done in one function
// if function returns something doesnt need to be assigned to variable apparently (as seen in public func)