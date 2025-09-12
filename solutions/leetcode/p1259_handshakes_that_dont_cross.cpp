using ll = long long;

class Solution {
private:
    ll solve(unordered_map<ll,ll>& memo, ll n) {
        if(n<2 || memo[n] != 0) {
            return memo[n];
        }

        ll res = 0;
        const ll MOD = 1e9 + 7;
        for(int i=1; i<n; i+=2) {
            ll l = i+1-2;
            ll m = 2;
            ll r = n - m - l;
            res += (solve(memo, l) * solve(memo, r) * solve(memo, m)) % MOD;
        }
        memo[n] = res % MOD;
        return memo[n];
    }

public:
    int numberOfWays(int numPeople) {
        const ll MOD = 1e9 + 7;

        unordered_map<ll,ll> memo;
        memo[0] = memo[2] = 1;
        solve(memo, numPeople);
        return memo[numPeople] % MOD;
    }
};

// can be solved a lot more efficiently bottom up
// but top down made more intuitive sense to me this time

// EVEN num of people arranged in a CIRCLE
// return the number of ways a handshake (every shaking) could occer
// return ans % MOD

// dp ?
// if I have 8 ppl and i cut it into 2 groups by connecting across
// i am left with a group of 2 and a group of 4 subproblem

// 4 = ans(2) + ans(2) = 1 + 1 = 2
// 6 = ( ans(2) * (ans(4)) ) + (ans(4) * ans(2)) + ((ans(2) * ans(2) * ans(2)))

// 8 = ans(2)*ans(6) + ans(2)*ans(2)*ans(4) + ans(4)*ans(2)*ans(2) + ans(2)*ans(6)
//   = 1*5 + 1*1*2 + 2*1*1 + 1*5 = 12

// clear recurrence relation, fix one and split into three groups with each connection
