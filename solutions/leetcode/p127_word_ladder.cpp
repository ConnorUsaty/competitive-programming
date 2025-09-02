class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> adj;
        for(auto& word : wordList) {
            for(int i=0; i<word.size(); ++i) {
                string key = word;
                key[i] = '#';
                adj[key].push_back(word); 
            }
        }

        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);
        int steps = 1;

        while(!q.empty()) {
            int s = q.size();
            for(int i=0; i<s; ++i) {
                string u = q.front();
                q.pop();

                if(u == endWord) return steps;

                for(int i=0; i<u.size(); ++i) {
                    string key = u;
                    key[i] = '#';
                    for(const string & v : adj[key]) {
                        if(visited.find(v) == visited.end()) {
                            q.push(v);
                            visited.insert(v);
                        }
                    }
                }
            }
            steps++;
        }

        return 0;
    }
};