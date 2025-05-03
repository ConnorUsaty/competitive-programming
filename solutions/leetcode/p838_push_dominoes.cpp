class Solution {
public:
    string pushDominoes(string d) {
        int n = (int)d.length();

        queue<int> q;
        for(int i=0; i<n; ++i){
            if(d[i]!='.'){
                q.push(i);
            }
        }

        string curr = d; // to store current state, cannot update d until entire state processed
        while(!q.empty()){
            int m = q.size();
            for(int i=0; i<m; ++i){
                int u = q.front();
                q.pop();
                if(d[u]=='R' && (u+1<n && d[u+1]=='.') && (u+2>=n || d[u+2]!='L')){
                    curr[u+1] = 'R';
                    q.push(u+1);
                }
                else if(d[u]=='L' && (u-1>=0 && d[u-1]=='.') && (u-2<0 || d[u-2]!='R')){
                    curr[u-1] = 'L';
                    q.push(u-1);
                }
            }
            d = curr;
        }
        return d;
    }
};

// bfs kinda solution
// O(n) time, each element can be pushed onto q a MAX of one time
// O(n) space, for q and for curr str