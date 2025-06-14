struct Node
{
    bool dead_ = false;
    string name_;
    vector<Node*> children_{};

    Node(string name) : name_(name) {}
};

class ThroneInheritance {
private:
    string king_name_;
    unordered_map<string,Node*> mp_;

    void dfs(vector<string>& ans, string curr){
        if(!mp_[curr]->dead_) ans.push_back(curr);

        for(auto const & c : mp_[curr]->children_){
            dfs(ans, c->name_);
        }
    }

public:
    ThroneInheritance(string kingName) {
        king_name_ = kingName;
        Node* king = new Node(kingName);
        mp_[king_name_] = king;
    }
    
    void birth(string parentName, string childName) {
        Node* child = new Node(childName);
        mp_[childName] = child;
        mp_[parentName]->children_.push_back(child);
    }
    
    void death(string name) {
        mp_[name]->dead_ = true;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(ans, mp_[king_name_]->name_);
        return ans;
    }
};

// should really have a custom destructor here to handle memory leaks

// create a graph of Node where Node has bool dead and vector<Node*> children
// dfs through list and add anyone thats not dead

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */