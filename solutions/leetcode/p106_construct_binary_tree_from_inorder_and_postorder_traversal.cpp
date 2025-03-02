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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,  unordered_map<int,int>& mp, int istart, int iend, int& pidx){
        
        if(istart>iend) return nullptr;
        
        int val = postorder[pidx];
        TreeNode* curr = new TreeNode(val);
        pidx--;
        
        if(istart != iend){
            int iidx = mp[val];
            curr->right = helper(inorder, postorder, mp, iidx+1, iend, pidx);
            curr->left = helper(inorder, postorder, mp, istart, iidx-1, pidx);
        }
        
        return curr;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = (int)inorder.size();
        int pidx = n-1;
        
        unordered_map<int,int> mp;
        for(int i=0; i<n; ++i){
            mp[inorder[i]] = i;
        }
        
        return helper(inorder, postorder, mp, 0, n-1, pidx);
    }
};

// last of postorder is root
// inorder[root_index-1] is left child of root

// we know postorder[pidx] is root of next subtree but we don't know if it is the left or right subtree
// we can use inorder idx to split into a left and right each time, allowing us to figure out if postorder[pidx] is the root of the left or right subtree
