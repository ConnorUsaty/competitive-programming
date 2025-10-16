class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<unordered_map<int,int>> seq(k+1);
        vector<int> res(k+1, 0);
        for(const int& n : nums) {
            for(int i=k; i>=0; --i) {
                seq[i][n] = max(seq[i][n]+1, (i>0 ? res[i-1] : 0) + 1);
                res[i] = max(res[i], seq[i][n]);
            }
        }
        return res[k];
    }
};

// track longest ss of all n for all k in map
// also track singular best ss for all k
// at each new number for all k check if any of our ss for that num or 
// singular best gets better
// have to start at k and go down to 0
// if we do it the other way around we will be updating it before querying it at the next iter and we would overcount


