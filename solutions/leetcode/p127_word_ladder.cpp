class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> adj;
        for(const string& word : wordList){
            for(int i=0; i<word.length(); ++i){
                string temp = word;
                temp[i] = '*';
                adj[temp].push_back(word);
            }
        }

        queue<string> Q;
        unordered_set<string> visited;
        Q.push(beginWord);
        visited.insert(beginWord);

        int ans = 1;
        while(Q.size() > 0){
            int s = Q.size();
            for(int i=0; i<s; ++i){
                string u = Q.front();
                Q.pop();
                if(u == endWord) return ans;
                for(int j=0; j<u.length(); ++j){
                    string temp = u;
                    temp[j] = '*';
                    for(const string& word : adj[temp]){
                        if(visited.find(word) == visited.end()){
                            Q.push(word);
                            visited.insert(word);
                        }
                    }
                }
            }
            ans++;
        }
        return 0; // not found
    }
};

// shortest unweighted path problem -> BFS

// can create a graph or adj list by making a key that would match all valid transformations and then pushing each to that key
// during BFS pop front, check if endWord, if not visit all adj words, and push them to Q if they have not been visited
// important to mark as visited at the same time we push to prevent duplicate pushes