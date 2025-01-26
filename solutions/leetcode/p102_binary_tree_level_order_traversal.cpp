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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> Q;
        Q.push(root);
        int h = 0;
        while(Q.size()>0){
            ans.push_back({});
            int s = Q.size();
            for(int i=0; i<s; ++i){
                TreeNode* t = Q.front();
                Q.pop();
                ans[h].push_back(t->val);
                if(t->left) Q.push(t->left);
                if(t->right) Q.push(t->right);
            }
            h++;
        }
        return ans;
    }
};

// to perform a level order traversal, BFS
// important to note that normally we should mark nodes as visited when pushing to Q
// since binary tree are DAG, we now there will not be repeated pushes and thus did not need a visited set
// get size before everything and perform all Q operations in for loop for level
