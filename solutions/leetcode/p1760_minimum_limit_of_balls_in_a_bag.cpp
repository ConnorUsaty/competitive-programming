class Solution {
private:
    bool check(int m, vector<int>& nums, int ops){
        for(const int & n : nums){
            ops -= ceil(n / (double)m)-1;
            if(ops<0) return false;
        }
        return true;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1, r=*max_element(nums.begin(), nums.end()) + 1;

        while(l<=r){
            int m = l+(r-l)/2;

            if(check(m, nums, maxOperations)){
                r = m-1;
            }else{
                l = m+1;
            }
        }

        return r+1;
    }
};