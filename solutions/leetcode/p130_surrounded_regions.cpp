typedef pair<int,int> pii;

class Solution {
private:
    void dfs(vector<vector<char>>& b, int i, int j){
        if(i<0 || i>=b.size() || j<0 || j>=b[0].size() || b[i][j]!='O') return;

        b[i][j] = '#';

        dfs(b,i,j+1);
        dfs(b,i+1,j);
        dfs(b,i,j-1);
        dfs(b,i-1,j);
    }

public:
    void solve(vector<vector<char>>& board) {
        // dfs from the borders
        // any reachable 'O' should be preserved
        for(int i=0; i<board.size(); ++i){
            if(board[i][0]=='O'){
                dfs(board,i,0);
            }
            if(board[i][board[0].size()-1]=='O'){
                dfs(board,i,board[0].size()-1);
            }
        }
        for(int i=0; i<board[0].size(); ++i){
            if(board[0][i]=='O'){
                dfs(board,0,i);
            }
            if(board[board.size()-1][i]=='O'){
                dfs(board,board.size()-1,i);
            }
        }
        
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(board[i][j]=='O') board[i][j] = 'X';
                else if(board[i][j]=='#') board[i][j] = 'O';
            }
        }
    }
};

// finding connections regions within grid -> DFS

// consider all points of DFS entry, i.e. instead of iterating over entire grid and entering on any 'O'
// we can instead iterate over only the borders and enter on any 'O', marking this 'O' as visited in place, and modifying the board after all DFS done
