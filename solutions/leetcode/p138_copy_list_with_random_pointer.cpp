/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*,Node*> seen;

        seen[head] = new Node(head->val);
        Node* new_head = seen[head];
        Node* p = new_head;
        while(head){
            if(head->next && seen.find(head->next) == seen.end()){
                seen[head->next] = new Node(head->next->val);
            }
            p->next = seen[head->next];

            if(head->random && seen.find(head->random) == seen.end()){
                seen[head->random] = new Node(head->random->val);
            }
            p->random = seen[head->random];

            p = p->next;
            head = head->next;
        }

        return new_head;
    }
};


// same style as copy graph
// map all the old nodes to the new node
// when setting each pointer, if weve already created a new node, set it to that
// if we have not created a new node, create it and record it in the map
