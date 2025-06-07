class Solution {
public:
        int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        for (int const & n : nums)
            for (int const & d : vector<int>(dp))
                dp[(n+d)%3] = max(dp[(n+d)%3], n+d);
        return dp[0];
    }
};

// check for biggest sum thats 

// to add 8 to n and get a sum divisible by 3, n%3 must = 1 = 3-(8%3)

// therefore track the 3 sums and at each [i] update all
// i.e. if we add 8, 8%3 = 2, we "shift" all answers 2 to the right
// our original 

// O(n) time, O(1) space since dp is always 3 idx regardless of input