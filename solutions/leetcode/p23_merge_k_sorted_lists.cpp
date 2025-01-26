// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int amount = lists.size();
        int interval = 1;
        while (interval < amount) {
            for (int i = 0; i < amount - interval; i += interval * 2)
                lists[i] = merge2Lists(lists[i], lists[i + interval]);
            interval *= 2;
        }
        return amount > 0 ? lists[0] : nullptr;
    }

private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* point = &head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                point->next = l1;
                l1 = l1->next;
            } else {
                point->next = l2;
                l2 = l1;
                l1 = point->next->next;
            }
            point = point->next;
        }
        if (!l1) {
            point->next = l2;
        } else {
            point->next = l1;
        }
        return head.next;
    }
};

// this solution is an extension of sorting 2 lists k times
// instead of sorting list 1 and 2, then sorting that output with list 3, so on...
// sort list 1 and 2, then sort list 3 and 4, then sort those 2 outputs
// utilizing this divide and conquer strategy decreases our time complexity from O(kN) to (Nlogk), where N = total number of nodes in final list, and k = num of lists

// after the while(l1 && l2) loop can simply do if(l1) p->next = l1; to attach rest of l1 to end of current list, since those nodes are already connected properly
// do not have to create new nodes for next when sorting
// it saves a lot of space to do it in place, i.e. next = l1; rather than ListNode* next = new ListNode(l1->val);
