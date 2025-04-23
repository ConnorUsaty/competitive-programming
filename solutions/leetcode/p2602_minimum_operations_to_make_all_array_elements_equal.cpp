class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n=(int)nums.size();

        sort(nums.begin(), nums.end());

        vector<long long> psum(n+1,0);
        for(int i=0; i<n; ++i) psum[i+1] = nums[i];
        for(int i=1; i<=n; ++i) psum[i] += psum[i-1];

        vector<long long> ans;
        for(const int& q : queries){
            int l=0, r=n-1;
            while(l<=r){
                int m = l+(r-l)/2;
                if (nums[m]<q){
                    l=m+1;
                } else {
                    r=m-1;
                }
            }
            long long before = psum[l];
            long long after = psum[n] - psum[l];
            ans.push_back((1LL*q*l - before) + (after - 1LL*q*(n-l)));
        }
        return ans;
    }
};

// O((n+q)logn) time, where n = num elements and q = num queries
// O(n) space, where n = num elements

// for prefix sums always do n+1 slots
// so that [0] can = 0 and any [i] can = sum BEFORE i
// then to get sum between do psum[r+1] - psum[l]
// make sure to use LL for sums or products of ints, they get large quickly and will overflow

// for query questions we often want to precompute results somehow
// prefix sums, fenwick trees, segment trees, etc. are common answers
