/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int traverse(TreeNode* t, int p, int q, TreeNode*& ans, int seen){
        if(t == nullptr || ans != nullptr) return seen;

        seen = traverse(t->left, p, q, ans, seen) + traverse(t->right, p, q, ans, seen);

        if(t->val == p || t->val == q) seen += 1;
        if (seen == 2){
            ans = t;
            seen += 1;
        }
        return seen;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        traverse(root, p->val, q->val, ans, 0);
        return ans;
    }
};

// since no ordering property like BST (can just search), have to visit all nodes and check