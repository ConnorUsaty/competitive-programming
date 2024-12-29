class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = (int)nums.size();
        int l=0, r=n-1;
        vector<int> ans(n);

        for (int i=n-1; i>=0; --i) {
            if(abs(nums[l]) > abs(nums[r])){
                ans[i] = nums[l]*nums[l++];
            } else {
                ans[i] = nums[r]*nums[r--];
            }
        }

        return ans;
    }
};

// initially I wanted to binary search for the swap from neg to pos then two ptr outwards resulting in O(logn + n)
// starting with two ptr initially and taking maxes while placing to back is O(n), therefore better solution