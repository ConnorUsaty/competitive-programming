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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        deque<TreeNode*> q;
        q.push_back(root);

        int level=0;
        while(!q.empty()){
            ans.push_back({});
            int s=q.size();
            for(int i=0; i<s; ++i){
                TreeNode* t;
                if(level&1){
                    t = q.back(); 
                    q.pop_back();
                    ans[level].push_back(t->val);
                    if(t->right) q.push_front(t->right);
                    if(t->left) q.push_front(t->left);
                }
                else{
                    t = q.front();
                    q.pop_front();
                    ans[level].push_back(t->val);
                    if(t->left) q.push_back(t->left);
                    if(t->right) q.push_back(t->right);
                }
            }
            level++;
        }
        return ans;
    }
};