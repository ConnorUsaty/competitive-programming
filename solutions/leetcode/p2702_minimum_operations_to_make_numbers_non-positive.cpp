class Solution {
private:
    bool check(vector<int>& nums, int x, int y, int m){
        // check if we can zero out the array in m ops
        int ops = m;
        for(auto& n : nums){
            int r = n - (y*m);
            if(r>0){
                ops -= (n - (m*y) + (x-y) - 1) / (x-y);
                if(ops<0) return false;
            }
        }
        return true;
    }

public:
    int minOperations(vector<int>& nums, int x, int y) {
        int l = 1, r = *max_element(nums.begin(), nums.end()) / y;

        while(l<=r){
            int m = l+(r-l)/2;
            if(!check(nums, x, y, m)){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return l;
    }
};