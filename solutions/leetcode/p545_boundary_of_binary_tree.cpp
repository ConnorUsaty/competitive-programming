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
    int set_left_flag(TreeNode* t, int flag) {
        if(flag == 0 || flag == 1) { // on lb
            return 1;
        }
        else if(flag == 2 && t->right == nullptr) { // on rb
            return 2;
        }
        return 3;
    }

    int set_right_flag(TreeNode* t, int flag) {
        if(flag == 0 || flag == 2) { // on rb
            return 2;
        }
        else if(flag == 1 && t->left == nullptr) { // on lb
            return 1;
        }
        return 3;
    }

    void preorder(TreeNode* t, vector<int>& lb, vector<int>& leaves, vector<int>& rb, int flag) {
        if(t == nullptr) return;

        if(flag == 0 || flag == 1) {
            lb.push_back(t->val);
        }
        else if (flag == 2) {
            rb.push_back(t->val);
        }
        else if (!t->left && !t->right) {
            leaves.push_back(t->val);
        }

        preorder(t->left, lb, leaves, rb, set_left_flag(t, flag));
        preorder(t->right, lb, leaves, rb, set_right_flag(t, flag));
    }

public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> lb, leaves, rb;
        preorder(root, lb, leaves, rb, 0);
        lb.insert(lb.end(), leaves.begin(), leaves.end());
        lb.insert(lb.end(), rb.rbegin(), rb.rend());
        return lb;
    }
};

// obviously we could easily split this up into three tasks but that would require us to revisit nodes

// we can do it in a singular pass by keeping track of what state we are in when we visit each node
// and based upon the state we can also continuously set the state for the children
// thus we know exactly what action to take the FIRST and ONLY time we visit each node

// O(n) time, O(n) memory