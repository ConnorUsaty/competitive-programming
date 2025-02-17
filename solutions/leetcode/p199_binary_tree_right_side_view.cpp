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
    void bfs(TreeNode* t, vector<int>& ans){
        queue<TreeNode*> Q;
        Q.push(t);
        while(Q.size() > 0){
            int s = Q.size();
            for(int i=0; i<s-1; ++i){
                TreeNode* u = Q.front();
                Q.pop();
                if(u->left) Q.push(u->left);
                if(u->right) Q.push(u->right);
            }
            // right most node in level
            TreeNode* rmn = Q.front();
            Q.pop();
            ans.push_back(rmn->val);
            if(rmn->left) Q.push(rmn->left);
            if(rmn->right) Q.push(rmn->right);
        }
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};

        vector<int> ans;
        bfs(root, ans);
        return ans;
    }
};

// level order traversal, return last element of each level