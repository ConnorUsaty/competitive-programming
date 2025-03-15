class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        const vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        vector<int> rook = getRookPos(board);

        int ans = 0;
        for(const auto& d : directions){
            int nx = rook[0]+d[0];
            int ny = rook[1]+d[1];
            while(nx>=0 && nx<8 && ny>=0 && ny<8 && board[nx][ny]=='.'){
                nx += d[0];
                ny += d[1];
            }
            if(nx>=0 && nx<8 && ny>=0 && ny<8 && board[nx][ny]=='p'){
                ans++;
            }
        }
        return ans;
    }
private:
    vector<int> getRookPos(vector<vector<char>>& board){
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(board[i][j]=='R'){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};