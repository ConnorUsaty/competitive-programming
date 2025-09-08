class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n, true);
        is_prime[0] = is_prime[1] = false;
        for(int i=2; i*i<n; ++i){
            if(is_prime[i]){
                for(int j=i*i; j<n; j+=i){
                    is_prime[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i=2; i<n; ++i){
            cnt += static_cast<int>(is_prime[i]);
        }
        return cnt;
    }
};

// for basically all primes questions -> sieve of eratosthenes -> O(n*log(log(n)))
// small opts for sieve such as going till i*i < n or doing all evens in advance
// need to set [0] [1] in advance and check that n >= 2
// start at j=i*i in inner loop and go j+=i