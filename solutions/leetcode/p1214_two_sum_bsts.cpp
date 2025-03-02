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
    void traverse(TreeNode* t, unordered_set<int>& t1_nodes){
        if(t == nullptr) return;

        traverse(t->left, t1_nodes);
        t1_nodes.insert(t->val);
        traverse(t->right, t1_nodes);
    }

    bool traverse_and_check(TreeNode* t, unordered_set<int>& t1_nodes, int target){
        if(t == nullptr) return false;

        int diff = target - t->val;
        if(t1_nodes.find(diff) != t1_nodes.end()) return true;
        
        return (traverse_and_check(t->left, t1_nodes, target)
            || traverse_and_check(t->right, t1_nodes, target));
    }

public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> t1_nodes;
        traverse(root1, t1_nodes);
        return traverse_and_check(root2, t1_nodes, target);
    }
};

// can use hashset solution similar to O(n) normal two sum solution
// get all nodes in tree 1 in a set
// then traverse tree 2 and check if the difference exists in tree 1
