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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* l = head;
        for(int i=0;i<left-1;++i){
            prev = l;
            l = l->next;
        }

        ListNode* p = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = l;
        for(int i=0; i<right-left+1; ++i) {
            next = curr->next;
            curr->next = p;
            p = curr;
            curr = next;
        }
        prev->next = p;
        l->next = next;
        return dummy->next;
    }
};