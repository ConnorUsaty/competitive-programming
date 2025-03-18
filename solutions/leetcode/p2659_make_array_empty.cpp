class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = (int)nums.size();

        // Fenwick tree set up
        const int MAX_N = 100001;
        int fwt[MAX_N+1];
        memset(fwt,0,sizeof(fwt));

        function<int(int)> query = [&](int i){
            i++;
            int s = 0;
            while(i>=1){
                s += fwt[i];
                i -= i&-i;
            }
            return s;
        };
        function<void(int,int)> add = [&](int i, int x){
            i++;
            while(i<=MAX_N){
                fwt[i] += x;
                i += i&-i;
            }
        };

        // map nums to sorted idx
        vector<int> idxs(n);
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(), [&](int i, int j){ return nums[i]<nums[j]; });

        // get ans
        long long ans = 0;
        int cur=0;
        for(int i=0; i<n; ++i){
            if(cur<=idxs[i]){
                ans += 1 + (idxs[i] - query(idxs[i])) - (cur - query(cur-1));
            } else {
                ans += (n - query(n)) + (idxs[i] - query(idxs[i])) - (cur - query(cur));
            }
            add(idxs[i], 1);
            cur = idxs[i];
        }
        return ans;
    }
};

// can just implement fenwick tree as array with lambda methods inside of scope, doesn't need to be own class
// remember to memset arrays to init their values
// when need full sorted order BUT don't need to update sorted order / insert just use sort() instead of pq
// can use fenwick tree to sum query and update intervals in O(logn)
// can only update singular indexes in O(logn), can query ranges in O(logn) though
