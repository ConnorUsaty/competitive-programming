class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = (int)nums.size();

        vector<int> ss = {nums[0]};
        for(int i=1; i<n; ++i){
            int idx = max(k - (n-i), 0);
            int l=idx, r=(int)ss.size()-1;
            while(l<=r){
                int m=l+(r-l)/2;
                if(ss[m]<=nums[i]){
                    l=m+1;
                }else{
                    r=m-1;
                }
            }
            if(l>(int)ss.size()-1 && (int)ss.size()<k){
                ss.push_back(nums[i]);
            }else if(l<=(int)ss.size()-1){
                ss = vector<int>(ss.begin(), ss.begin()+l);
                ss.push_back(nums[i]);
            }
        }
        return ss;
    }
};

// subsequence of size k
// more competitve if lower at first difference at [i] where i any idx in ss

// always better to restart ss if we find a lower a[i] that still has k-1 elements after it
// if >= use binary search to insert into ss
// if a[i] < ss[0] AND NOT k-1 elements remaining, compare with [1] or etc.

// Was able to get AC O(nlogk) time, O(k) space with solution above



// However there is a much simpler solution (found in solutions)
// Since it is always better to take a lower element if possible (idx cond) we can use a monotonic stack, meaning that each item in the stack is >= all elements before it
// O(n) time, O(k) space

// Keep in mind for future problems if we make an observation that we can greedily take >= or <= elements, monotonic stack / queue may be a good solution for O(n) time

vector<int> mostCompetitive(vector<int>& A, int k) {
    vector<int> stack;
    for (int i = 0; i < A.size(); ++i) {
        while (!stack.empty() && stack.back() > A[i] && stack.size() - 1 + A.size() - i >= k)
            stack.pop_back();
        if (stack.size() < k)
            stack.push_back(A[i]);
    }
    return stack;
}
