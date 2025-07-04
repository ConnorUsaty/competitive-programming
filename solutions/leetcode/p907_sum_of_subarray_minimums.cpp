class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=(int)arr.size();

        stack<int> stk;
        long long ans = 0;
        long long const MOD = 1e9 + 7;

        for(int i=0; i<n; ++i){
            while(!stk.empty() && arr[i]<arr[stk.top()]){
                int m = stk.top();
                stk.pop();
                int l = (stk.empty() ? -1 : stk.top());
                int r = i;
                ans = (ans + (1LL*(r-m)*(m-l)*arr[m] % MOD)) % MOD;
            }
            stk.push(i);
        }

        while(!stk.empty()){
            int m = stk.top();
            stk.pop();
            int l = (stk.empty() ? -1 : stk.top());
            int r = n;
            ans = (ans + (1LL*(r-m)*(m-l)*arr[m] % MOD)) % MOD;
        }
        return static_cast<int>(ans);
    }
};

// monotonic stack problem
// each elements contribution is bounded by the first number < it on the left and right side
// we can process logic like this in O(n) time and space with a monotonic stack
