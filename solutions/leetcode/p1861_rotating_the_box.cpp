class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = (int)boxGrid.size(), m = (int)boxGrid[0].size();
        vector<vector<char>> ans(m, vector<char>(n, '.'));
        
        for(int i=n-1; i>=0; --i){
            int place = m-1;

            for(int j=m-1; j>=0; --j){
                if(boxGrid[i][j]=='*'){
                    ans[j][n-1-i]='*';
                    place = j-1;
                }
                else if(boxGrid[i][j]=='#'){
                    ans[place][n-1-i]='#';
                    place--;
                }
            }
        }
        return ans;
    }
};

// can start from bottom of rotated box, each time we encounter an item, move it as low down as possible
// by placing it at "place" which is the next avail idx, i.e. 1 above the last placed item or wall
// when we place an item, move place up one, so the next item will fall on top of this item
// when we place a wall, move place one above the wall as items cannot move through it
