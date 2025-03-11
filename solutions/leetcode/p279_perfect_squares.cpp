class Solution {
public:
    int numSquares(int n) {
        vector<int> squares = getSquares(n);
        vector<int> visited(n+1, 0);
        queue<int> q;
        q.push(0);

        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i=0; i<s; ++i){
                int u = q.front();
                q.pop();
                if(u == n){
                    return ans;
                }
                for(const int& v : squares){
                    if(v+u>n || visited[v+u]) continue;
                    q.push(v+u);
                    visited[v+u] = 1;
                }
            }
            ans++;
        }
        return -1;
    }

private:
    vector<int> getSquares(const int n){
        vector<int> squares;
        for(int i=1; i*i<=n; ++i){
            squares.push_back(i*i);
        }
        return squares;
    }
};

// greedy doesnt work
// dp ?
// get all perfect squares <= n
// then build up ans

// LEAST NUM OF SQUARES -> SHORTEST PATH PROBLEM -> BFS