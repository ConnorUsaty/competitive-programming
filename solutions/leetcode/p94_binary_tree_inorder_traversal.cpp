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
    void traverse(TreeNode* t, vector<int>& ans) {
        if(t == nullptr) return;

        traverse(t->left, ans);
        ans.push_back(t->val);
        traverse(t->right, ans);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};

// can also do iteratively with a stack
// keep pushing left to stack until null
// then push parent to ans
// then push right to stack
// then repeat
