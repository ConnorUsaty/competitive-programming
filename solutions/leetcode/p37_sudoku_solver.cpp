class Solution {
private:
    std::array<std::array<bool, 9>, 9> r_mp;
    std::array<std::array<bool, 9>, 9> c_mp;
    std::array<std::array<bool, 9>, 9> s_mp;

    bool backtrack(size_t row, size_t col, vector<vector<char>>& board) {
        // preset square
        if(board[row][col]>='1' && board[row][col]<='9') {
            if (col<board.size()-1) {
                return backtrack(row, col+1, board);
            }
            else if (row<board.size()-1){
                return backtrack(row+1, 0, board);
            }
            else {
                return true;
            }
        }

        // brute force fill in
        for(size_t num=0; num<9; ++num){
            if(!r_mp[row][num] && !c_mp[col][num] && !s_mp[(row/3)*3 + col/3][num]) {
                r_mp[row][num] = true;
                c_mp[col][num] = true;
                s_mp[(row/3)*3 + col/3][num] = true;
                board[row][col] = static_cast<char>(num+'1');

                if (col<board.size()-1) {
                    if(backtrack(row, col+1, board)) return true;
                } else if (row<board.size()-1){
                    if(backtrack(row+1, 0, board)) return true;
                } else {
                    return true;
                }

                // didnt work, cleanup
                r_mp[row][num] = false;
                c_mp[col][num] = false;
                s_mp[(row/3)*3 + col/3][num] = false;
                board[row][col] = '.';
            }
        }
        // this path as a whole is incorrect, backtrack
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        std::fill(r_mp.begin(), r_mp.end(), std::array<bool, 9>{});
        std::fill(c_mp.begin(), c_mp.end(), std::array<bool, 9>{});
        std::fill(s_mp.begin(), s_mp.end(), std::array<bool, 9>{});
        for(size_t row=0; row<board.size(); ++row) {
            for(size_t col=0; col<board.size(); ++col) {
                if(board[row][col] != '.') {
                    int num = board[row][col] - '0';
                    r_mp[row][num-1] = true;
                    c_mp[col][num-1] = true;
                    s_mp[(row/3)*3 + col/3][num-1] = true;
                }
            }
        }
        backtrack(0, 0, board);
    }
};

// can check if alr present in row col or square in O(1) using 3 2D arrays
// then backtrack and try all options
// always return on preset squares
// fill maps with preset values in advance to eliminate bad paths earlier

// use std::array since we know array sizes at compile time -> this gives better memory locality
// need to use std::fill to init our std::array
// be explicit with casts and do not use magic numbers