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
    void helper(TreeNode*& t, vector<int>& pre_order, size_t& pre_idx, int l, int r, unordered_map<int,int>& inorder_val_to_idx) {
        if(l>r) return;

        t = new TreeNode(pre_order[pre_idx++]);
        int inorder_idx = inorder_val_to_idx[t->val];

        helper(t->left, pre_order, pre_idx, l, inorder_idx-1, inorder_val_to_idx);
        helper(t->right, pre_order, pre_idx, inorder_idx+1, r, inorder_val_to_idx);
    }

public:
    TreeNode* buildTree(vector<int>& pre_order, vector<int>& inorder) {
        size_t pre_idx = 0;
        unordered_map<int,int> inorder_val_to_idx;
        for(int i=0; i<inorder.size(); ++i) {
            inorder_val_to_idx[inorder[i]] = i;
        }

        TreeNode* root = nullptr;
        helper(root, pre_order, pre_idx, 0, inorder.size()-1, inorder_val_to_idx);
        return root;
    }
};

// next pre_idx is parent of left subtree if there is anymore nodes in the inorder partition
// else return and do right subtree

// in order traversal (L, P, R) of a BST will always give a sorted arr
// pre order is (P, L, R)

// we can use pre order to identify the parent and split in order in half