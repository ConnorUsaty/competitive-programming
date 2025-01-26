class Solution {
private:
    bool dfs(vector<vector<char>>& b, int i, int j, string w, int k){
        if(k>=w.length()) return true;
        if(i<0 || i>=b.size() || j<0 || j>=b[0].size() || b[i][j]!=w[k]) return false;

        b[i][j] = '#';

        if (dfs(b, i, j-1, w, k+1)) return true;
        if (dfs(b, i, j+1, w, k+1)) return true;
        if (dfs(b, i-1, j, w, k+1)) return true;
        if (dfs(b, i+1, j, w, k+1)) return true;

        b[i][j] = w[k];

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};

// only checking for one singular word -> no need for trie
// just dfs / backtrack

// bt(board,i,j,word,k)

// remember to mark node as visited before dfs onto adjacent nodes
// can remark node to original after performing dfs on the adjacents

// standard dfs, check if solved, then check basecase, then mark visited, then dfs adjacents, then remark to original, then return