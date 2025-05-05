class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=(int)nums.size();
        vector<int> valid(n+1, 0);
        valid[0]=1;

        for(int i=1; i<n; ++i){
            if(!valid[i-1]) continue;

            if(nums[i-1]==nums[i]){
                valid[i+1]=1;
                if(i+1<n && nums[i]==nums[i+1]){
                    valid[i+2]=1;
                }
            }
            else if(nums[i-1]+1==nums[i] && i+1<n && nums[i]+1==nums[i+1]){
                valid[i+2]=1;
            }
        }
        return valid[n];
    }
};

// paritions are always of size 2 or 3
// check for each type of parition and mark as a valid end point
// move to next [i], if [i-1] not valid skip as we cannot start a new parition here
// continue for all i, return valid[n-1]