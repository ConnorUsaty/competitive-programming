class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows>=s.length() || numRows==1) return s;

        // Get chars in row format
        int idx=0, direction=-1;
        vector<vector<char>> rows(numRows);
        for(const char& c : s) {
            rows[idx].push_back(c);
            if(idx==numRows-1){
                direction=-1;
            }
            else if (idx==0){
                direction=1;
            }
            idx+=direction;
        }

        // Create ans string
        string ans="";
        for(int i=0;i<numRows;++i){
            for(const char& c : rows[i]){
                ans.push_back(c);
            }
        }
        return ans;
    }
};

// Remember to look for edge cases