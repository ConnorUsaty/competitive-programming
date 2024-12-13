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
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return; // Edge cases

        deque<ListNode*> Q;
        ListNode* temp = head->next;
        while(temp){
            Q.push_back(temp);
            temp = temp->next;
        }

        while(Q.size()>=2){
            head->next = Q.back();
            Q.pop_back();
            head = head->next;
            head->next = Q.front();
            Q.pop_front();
            head = head->next;
        }

        if(!Q.empty()){
            head->next = Q.back();
            head = head->next;
        }
        head->next = NULL;
    }
};

// traverse list placing nodes into deque
// when end of list is reached start setting curr->next
// do this by popping back then popping front until deque empty

// can be done with stack, keeping every other node then swapping ptrs to save memory and time
// need to set last nodes ->next to null to prevent cycle within list