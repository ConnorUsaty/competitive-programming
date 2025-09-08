/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* p = head;
        while(p && p->next) {
            ListNode* first = p;
            ListNode* second = p->next;

            next = second->next;
            second->next = first;
            first->next = next;
            if(prev) prev->next = second;
            else head = second;
            prev = first;
            p = prev->next;
        }
        return head;
    }
};

// make sure there are 2 more nodes to flip
// get next / prev of pair
// flip both and connect to next / prev
// repeat
// O(n) time, O(1) space