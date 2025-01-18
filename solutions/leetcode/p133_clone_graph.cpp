/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* dfs(Node* node, std::unordered_map<Node*,Node*>& mp){
        Node* copy = new Node(node->val);
        mp[node] = copy;
        for(auto n : node->neighbors){
            if(mp.find(n)!=mp.end()){
                copy->neighbors.push_back(mp[n]);
            }
            else{
                copy->neighbors.push_back(dfs(n,mp));
            }
        }
        return copy;
    }

public:
    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*,Node*> mp;
        if(node == nullptr) return nullptr;
        else if(node->neighbors.size()==0){
            Node* res = new Node(node->val);
            return res;
        }
        return dfs(node, mp);
    }
};

// dfs to all nodes, even if visited node before (found in mp) we still push to back we just do not have to visit again to build adj list