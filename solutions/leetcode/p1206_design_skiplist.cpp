class Skiplist {
private:
    class Node;
public:
    
    Skiplist() {
        srand(time(NULL));
        topLeft_head = nullptr;
        this->add(-inf);
    }
    bool coinflip() {
        return (rand()%2 == 0);
    }
    
    Node* findNode(int target) {
        if (topLeft_head == nullptr) return nullptr;
        Node* p = topLeft_head;
        while (p->bottom != nullptr) {
            p = p->bottom;
            while (p->next != nullptr && target >= p->next->val) {
                p = p->next;
            }
        }
        while (p->next != nullptr && target >= p->next->val) {
            p = p->next;
        }
        return p;
    }
    bool search(int target) {
        if (topLeft_head == nullptr) return false;
        Node* p = findNode(target);
        return p->val == target;
    }
    
    void createNewLevel() {
        Node* new_topleft = new Node(topLeft_head->val);
        new_topleft->bottom = topLeft_head;
        topLeft_head->up = new_topleft;
        topLeft_head = new_topleft;
    }
    
    void insert(Node* a, Node* b) {
        // insert b after a
        b->next = a->next;
        if (a->next != nullptr) a->next->prev = b;
        a->next = b;
        b->prev = a;
    }
    
    void add(int num) {
        if (topLeft_head == nullptr) {
            // empty skiplist
            topLeft_head = new Node(num);
            level = 1;
            return;
        }
        
        Node* p = findNode(num);
        Node* q = new Node(num);
        int i = 1;
        insert(p, q);
        while (coinflip()) {
            // insert into this layer
            i = i + 1;
            if (i > level) {
                level = level + 1;
                createNewLevel();
            }
            while (p->up == nullptr) {
                p = p->prev;
            }
            p = p->up;
            Node* new_q = new Node(num);
            new_q->bottom = q;
            q->up = new_q; 
            q = new_q;
            insert(p, q);
        }
    }
    
    bool erase(int num) {
        Node* p = findNode(num);
        if (p == nullptr || p->val != num) return false;
        while (1) {
            p->prev->next = p->next;
            if (p->next != nullptr) p->next->prev = p->prev;
            if (p->up == nullptr) break;
            p = p->up;
            delete p->bottom;
            p->bottom = nullptr;
        }
        return true;
    }
    
private:
    class Node{
    public:
        Node(int _val) {
            this->val = _val;
            this->prev = nullptr;
            this->next = nullptr;
            this->up = nullptr;
            this->bottom = nullptr;
        }
        Node(int _val, Node* _prev, Node* _next, Node* _up, Node* _bottom) {
            this->val = _val;
            this->prev = _prev;
            this->next = _next;
            this->up = _up;
            this->bottom = _bottom;
        }
        
        Node* prev;
        Node* next;
        Node* up;
        Node* bottom;
        int val;
    };
    
    Node* topLeft_head;
    int level;
    const int inf = (1<<30);
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */