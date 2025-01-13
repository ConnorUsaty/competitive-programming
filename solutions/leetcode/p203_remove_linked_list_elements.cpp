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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;

        while(head && head->val==val){
            ListNode* t = head;
            head = head->next;
            delete t; 
        }
        
        ListNode* p = head;
        while(p && p->next){
            if(p->next->val==val){
                ListNode* t = p->next;
                p->next = p->next->next;
                delete t;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};

// have to consider case where head is null, head is val, first x vals are val
// after that just progress through ll removing and deleting any nodes of that val
// have to ensure ptr is not null before trying to dereference and access any of its member variables
// we can only go to p->next if we did NOT perform a deletion -> else we risk skipped a val if we get a situation like val=3, [0, 1, 3, 3, 3]