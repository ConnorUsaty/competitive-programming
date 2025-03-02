class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int m = (int)cells.size();
        vector<int> prev = cells;
        
        // do first state seperately due to first / last
        for(int j=1; j<m-1; ++j){
            if(prev[j-1]==prev[j+1]) cells[j] = 1;
            else cells[j] = 0;
        }
        cells[0] = 0;
        cells[m-1] = 0;
        prev = cells;

        // only 14 possible states
        int states = (n-1)%14;
        for(int i=0; i<states; ++i){
            for(int j=1; j<m-1; ++j){
                if(prev[j-1]==prev[j+1]) cells[j] = 1;
                else cells[j] = 0;
            }
            prev = cells;
        }
        return cells;
    }
};

// naive solution is to brute force and actually "do the simulation" resulting in O(n)
// however N can be up to 1e9 which results in TLE
// intuitively the only way to cut down from O(n) is to find a pattern within the states
// with a bit of testing using cout, was able to find out that there are only 14 possible states
