class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand=0, cnt=0;

        for(int n : nums){
            if(n==cand || cand==0){
                cnt++;
                cand=n;
            }
            else if(--cnt==0){
                cand=0;
            }
        }

        return cand;
    }
};

// IMPORTANT NOTE -> Boyer Moore Majority Voting Algorithm typically requires second loop to ensure candidate is indeed majority
// SINCE we can assume that majority element ALWAYS occurs given Leetcode constraints only the first loop is needed -> Candidate will always be majority
// HOWEVER if we could not assume that, we would require a second loop that ensyres the count of our candidate element is indeed > floor(n/2)