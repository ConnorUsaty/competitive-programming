class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int ans = nums[0];
        for(int i=1; i<nums.size(); ++i){
            ans = gcd(ans, nums[i]);
            if(ans == 1) return true;
        }
        return ans == 1;
    }
};

// O(log(n)) is BETTER than O(root(n))
// gcd(a,b) = O(log(min(a, b))) time

// if ANY of ANY numbers multiples are 1 away -> TRUE
// else -> FALSE

// if we have an odd and an even that are NOT multiples of each other -> TRUE

// check if they share NO prime factors with anything we've already processed?

// O(n * log(n))