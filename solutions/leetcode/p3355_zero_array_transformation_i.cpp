class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n=(int)nums.size(), m=(int)q.size();
        
        vector<int> dec(n+1,0);
        for(int i=0; i<m; ++i){
            dec[q[i][0]]++;
            dec[q[i][1]+1]--;
        }

        int curr=0;
        for(int i=0; i<n; ++i){
            curr += dec[i];
            if(nums[i]-curr>0) return false;
        }
        return true;
    }
};

// similar to meeting rooms interval problem
// can check if enough intervals fall on top of nums[i]