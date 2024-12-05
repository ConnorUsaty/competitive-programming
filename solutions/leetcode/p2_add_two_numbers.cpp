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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode newHead(0);
        ListNode *t = &newHead;
        while(c || l1 || l2) {
            if(l1){
                c+=l1->val;
                l1=l1->next;
            }
            if(l2){
                c+=l2->val;
                l2=l2->next;
            }
            t->next = new ListNode(c%10);
            t = t->next;
            c /= 10;
        }
        return newHead.next;
    }
};