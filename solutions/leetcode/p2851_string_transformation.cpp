class Solution {
private:
    template <typename T>
    T fastPow(T a, T b, const T m){
        if (a==0) {
            return b==0;
        }

        bool negative = false;
        if(b<0) {
            b = -b;
            negative = true;
        }

        T ans=1;
        while(b>0){
            if (b&1) ans = (ans*a) % m; // if b is odd
            b >>= 1LL; // right shift once (divide by 2)
            a = (a*a) % m;
        }
        return (negative ? 1/ans : ans);
    }

    long long modInverse(long long a, long long m) {
        return fastPow(a, m - 2, m);
    }

public:
    int numberOfWays(string s, string t, long long k) {
        const long long n = static_cast<int>(s.size());
        const long long MOD = 1e9+7;
        const long long p = 999'999'937;

        long long t_hash = 0;
        for(const char& c : t) {
            t_hash *= p;
            t_hash = (t_hash + (c-'a')) % MOD;
        }

        long long s_hash = 0;
        for(const char& c : s) {
            s_hash *= p;
            s_hash = (s_hash + (c-'a')) % MOD;
        }

        long long res = 0;
        long long largest_power = fastPow(p, n-1, MOD);
        long long fk1 = (fastPow((n - 1), k, MOD) - fastPow(-1LL, k, MOD)) * modInverse(n, MOD);
        for(int i=0; i<n; ++i) {
            if(s_hash == t_hash) {
                res += (i != 0 ? fk1 : fk1 + fastPow(-1LL, k, MOD));
                res %= MOD;
            }

            // remove first char in current rotation
            s_hash = (s_hash - ((s[i]-'a') * largest_power)) % MOD;

            // fix MOD arithmetic
            s_hash = (s_hash % MOD + MOD) % MOD;

            // re add as last char
            s_hash = ((s_hash * p) + (s[i]-'a')) % MOD;
        }
        return res;
    }
};

// by removing suffix and appending to start we are essentially just rotating
// by k char where k = suffix size
// suffix CAN be empty

// return NUM of ways to transform s into t in EXACTLY k ops
// return it MOD 1e9+7

// dp[i][k] number of ways to rotate s by i to the left in exactly k ops

// use rolling hash to identify all valid rotations that result in t
// use dp to determine how many of those rotations are possible in k ops


// we can compute rolling hashes to very efficiently compare strings
// it also works for comparing string rotations
// we just choose A and B to be large prime numbers
// for comparing n strings with the other n-1 strings we should compute two hashes and make sure they both match to avoid false positive collisions