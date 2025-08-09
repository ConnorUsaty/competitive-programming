class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        const int MOD = 1e9+7;

        sort(packages.begin(), packages.end());
        long long package_sum = std::accumulate(packages.begin(), packages.end(), 0LL);
        long long ans = std::numeric_limits<long>::max();

        for(auto& supplier : boxes){
            sort(supplier.begin(), supplier.end());
            if(supplier.back() < packages.back()) continue;
            long long space_used = 0, l = 0;
            // for each box for this supplier
            // find out how many packages it can cover
            for(auto& b : supplier){
                long long start = l, r = packages.size()-1;
                while(l<=r){
                    long long m=l+(r-l)/2;
                    if(packages[m]<=b){
                        l=m+1;
                    }else{
                        r=m-1;
                    }
                }
                space_used += (l - start) * b;
            }
            ans = min(ans, space_used);
        }

        return (ans == std::numeric_limits<long>::max() ? -1 : (ans-package_sum) % MOD);
    }
};