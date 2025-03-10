class Solution {
private:
    bool bfs(int n, int root, vector<int>& left, vector<int>& right){
        queue<int> q;
        vector<int> visited(n, 0);
        visited[root] = 1;
        q.push(root);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(left[u]!=-1){
                if(visited[left[u]]) return false;
                q.push(left[u]);
                visited[left[u]] = 1;
            }
            if(right[u]!=-1){
                if(visited[right[u]]) return false;
                q.push(right[u]);
                visited[right[u]] = 1;
            }
        }
        for(const int& n : visited) if(n==0) return false;
        return true;
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> nodes(leftChild.begin(), leftChild.end());
        nodes.insert(rightChild.begin(), rightChild.end());

        int root=-1;
        for(int i=0; i<n; ++i){
            if(nodes.find(i) == nodes.end()){
                root = i;
                break;
            }
        }
        if(root==-1) return false;

        return bfs(n, root, leftChild, rightChild);
    }
};

// is valid binary tree iff 0-2 children, no cycles, fully connected
// can verify with bfs BUT need to find root first
// root will be node with indegree 0
// O(n) time
// O(n) space