class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        Node* left = root;
        while (left->left != nullptr) {
            Node* head = left;
            while (head != nullptr) {
                head->left->next = head->right;
                if (head->next != nullptr) {
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            left = left->left;
        }
        return root;
    }
};

// can use each level as a LL for O(1) space
// I believe this only works because it is guarenteed to be a perfect binary tree
// ^ O(1) space opt can still be done with non-perfect tree but takes much more setup