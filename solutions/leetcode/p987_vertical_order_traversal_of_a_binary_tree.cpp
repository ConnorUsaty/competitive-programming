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

struct Props{
    TreeNode* t;
    int col;
    int row;

    Props(TreeNode* node, int c, int r) : t(node), col(c), row(r) {}
};

class Solution {
private:
    int mn;
    int mx;

    void bfs(TreeNode* t, unordered_map<int,vector<pair<int,int>>>& mp){
        queue<Props> q;
        q.push({t,0,0});

        while(!q.empty()){
            int s = q.size();
            for(int i=0; i<s; ++i){
                Props p = q.front();
                q.pop();
                mp[p.col].push_back({p.row, p.t->val});
                mx = max(mx, p.col);
                mn = min(mn, p.col);
                if(p.t->left) q.push({p.t->left, p.col-1, p.row+1});
                if(p.t->right) q.push({p.t->right, p.col+1, p.row+1});
            }
        }
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, vector<pair<int,int>>> cols; // key = col, val = {row, val}

        mn = 0;
        mx = 0;
        bfs(root, cols); // bfs tree and fill map

        vector<vector<int>> ans(mx-mn+1);
        int ans_idx = 0;

        // sort each column to ensure vals are ordered asc by row, val
        for(int i=mn; i<=mx; ++i){
            sort(cols[i].begin(), cols[i].end());
            for(const auto& p : cols[i]){
                ans[ans_idx].push_back(p.second); // push sorted elements to ans
            }
            ans_idx++;
        }

        return ans;
    }
};