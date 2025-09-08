/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* t = node->next;
        node->next = node->next->next;
        delete t;
    }
};

// O(1) time, O(1) space

// cannot go back to reconnect prev to node->next
// we can only go forward
// set node->val to node->next->val