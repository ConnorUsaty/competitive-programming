const long long MOD = 1e9+7;

class Solution {
private:
    long long inv(long long a){
        return (a==1 ? a : (MOD-MOD/a) * inv(MOD%a) % MOD);
    }

public:
    int numberOfWays(int startPos, int endPos, int k) {
        long long diff = abs(startPos-endPos);
        if(diff>k || (k-diff)&1) return 0;

        long long ans = 1LL;
        for(long long i=0; i<(k-diff)/2; ++i){
            ans  = (ans * (k-i)) % MOD;
            ans  = (ans * inv(i+1)) % MOD;
        }
        return ans;
    }
};

// problem can be turned into finding nCr combinations
// where n = k, and r = k-diff/2
// to find nCr = n! / ((n-r)! * r!) we can do n! * inv(n-r) * inv(r)
// can compute inv in log(k) we can use bin expo
