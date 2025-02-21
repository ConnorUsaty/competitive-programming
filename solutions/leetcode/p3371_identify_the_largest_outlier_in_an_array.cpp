class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long long sm = 0;
        unordered_map<int,int> cnt;
        for(const int& n : nums){
            sm += n;
            cnt[n*2]++;
        }
        int ans = INT_MIN;
        for(const int& n : nums){
            int t = sm - n; // treat n as outlier
            if((cnt[t]>=2) || (cnt[t]==1 && t!=2*n)){
                ans = max(ans, n);
            }
        }
        return ans;
    }
};

// for any element n to be a valid outlier, the sum without n needs to be equal to any element*2
// track cnt of each element and get total sum, then do second pass treating each n as possible outlier and take max ans
// need cnt to handle edge case of the sum - n = n, this case is invalid when cnt[n] = 1, as we already used n as our other special element (the outlier)

// O(n) time, O(n) space