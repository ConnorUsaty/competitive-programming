class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0, curr=0, ans=1e9;
        while(r<nums.size()){
            while(r<nums.size() && curr<target){
                curr+=nums[r];
                r++;
            }
            while(l<r && curr>=target){
                curr-=nums[l];
                l++;
                ans = min(ans, r-l+1);
            }
        }
        return (ans==1e9) ? 0 : ans;
    }
};

// subarray = window -> two ptr
// expand window until >= target
// close window until no longer >= target
// keep track of min window size >= target



// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int ans=1e9, curr=0;
//         deque<int> Q;

//         for(int i=0;i<nums.size();++i){
//             Q.push_back(nums[i]);
//             curr += nums[i];

//             while(!Q.empty() && curr>=target){
//                 ans = min(ans, (int)Q.size());
//                 curr -= Q.front();
//                 Q.pop_front();
//             }
//         }
        
//         return (ans<1e9)?ans:0;
//     }
// };


// deque's are very useful for sliding window problems as you can push to the back and pop from front to shorten / extend the window
// remember to deal with edge cases including case where ans does not exist
// can be done without deque using 2 ptr's for O(1) memory