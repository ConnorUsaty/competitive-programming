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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = nullptr;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode* group_first = nullptr;
        ListNode* p = head;
        while(p){
            // check that there a k more nodes to reverse
            ListNode* check = p; // group_next
            for(int i=0; i<k; ++i){
                if(!check) return res ? res : head;
                check = check->next;
            }
            // reverse the k
            ListNode* group_prev = group_first;
            group_first = p;
            for(int i=0; i<k; ++i) {
                next = p->next;
                p->next = prev;
                prev = p;
                p = next;
            }
            group_first->next = check;
            if(group_prev) group_prev->next = prev;
            if(!res) res = prev;
        }
        return res;
    }
};