class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxNeg = nums[0];
        int maxPos = nums[0];
        int ans = nums[0];

        for(int i=1; i<nums.size(); ++i){
            int n = nums[i];
            if(n<0){
               swap(maxPos, maxNeg);
            }
            maxPos = max(n, maxPos * n);
            maxNeg = min(n, maxNeg * n);
            ans = max(ans, maxPos);
        }

        return ans;
    }
};

// can apply similar to maximum sum with some modifications

// keep track of the lowest possible and the biggest possible product at each index
// whenever we hit a negative number, flip them
// ans is the biggest positive we are able to make at any given index