class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n = nums.size();

        long long expected_sum = n*(n+1)/2;
        long long actual_sum = std::accumulate(nums.begin(), nums.end(), 0*1LL);

        return expected_sum - actual_sum;
    }
};

// can use 1 to n summation formula to find expected sum
// can use std::accumulate to get actual sum

// missing number is the difference

// this works because the list is n DISTINCT numbers from 1 to n, meaning we expect the sum to be a 1 to n summation

// ensure to use long long with accumulate, as sums can grow large and overflow integers
