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
    pair<int,int> post_order(TreeNode* t, int& ans){
        if(t == nullptr) return {0,0};

        pair<int,int> left = post_order(t->left, ans);
        pair<int,int> right = post_order(t->right, ans);
        int subtree_sum=t->val+left.first+right.first;
        int subtree_cnt=1+left.second+right.second;

        if(subtree_sum/subtree_cnt == t->val) ans++;
        return {subtree_sum, subtree_cnt};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        post_order(root, ans);
        return ans;
    }
};

// subtrees are inclusive of node, i.e. leafs subtree = leaf

// post order traversal, check cond, ans++