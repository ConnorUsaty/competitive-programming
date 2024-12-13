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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        stack<ListNode*> stk;
        while(ptr){
            stk.push(ptr);
            ptr = ptr->next;
        }

        if(n==stk.size()){
            ListNode* new_head = head->next;
            delete head;
            return new_head;
        }

        for(int i=1; i<n; ++i){
            stk.pop();
        }

        ListNode* temp = stk.top(); // node to be removed
        stk.pop();
        stk.top()->next = temp->next; // node before removed node
        delete temp;

        return head;
    }
};

// can use stack again
// can use fast / slow ptr approach to find nth last node and remove in O(1) extra space
// O(n) time for both but only one pass for two ptr approach

// remember to handle edge cases like n == size of LL (remove first node)