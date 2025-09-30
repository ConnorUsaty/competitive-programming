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
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int s = q.size();
            for(int i=0; i<s; ++i) {
                TreeNode* u = q.front();
                q.pop();

                if(!u->left && !u->right) return level;
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            level++;
        }
        return -1;
    }
};