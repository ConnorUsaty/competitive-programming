class Solution {
private:
    unordered_map<char,vector<char>> options = {
        {'0', {'9', '1'}},
        {'1', {'0', '2'}},
        {'2', {'1', '3'}},
        {'3', {'2', '4'}},
        {'4', {'3', '5'}},
        {'5', {'4', '6'}},
        {'6', {'5', '7'}},
        {'7', {'6', '8'}},
        {'8', {'7', '9'}},
        {'9', {'8', '0'}},
    };

public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if(visited.find("0000") != visited.end()) return -1;
        q.push("0000");
        visited.insert("0000");

        int moves = 0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0; i<s; ++i){
                string u = q.front();
                q.pop();
                if(u==target) return moves;

                for(int j=0; j<4; ++j){
                    char key = u[j];
                    for(const char& c : options[key]){
                        string v = u;
                        v[j] = c;
                        if(visited.find(v) == visited.end()){
                            q.push(v);
                            visited.insert(v);
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};

// return min num of turns -> SHORTEST PATH PROBLEM -> BFS
// can BFS with "0000" as start, "0000" is adj to +-1 at each idx
// therefore to simulate adj list iterate over all idx of curr string u and try to go up or down one
// if visited do nothing, else push to q and mark as visited
// when curr string u == target, return num of moves it took to get there

// 9 to 0, 0 to 9
// init 0000
// if deadend, over
// given target return min num of turns to open lock or -1 if impossible
// min num of turns -> shortest path ? -> BFS
    