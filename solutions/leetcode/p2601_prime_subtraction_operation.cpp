class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        const int MAX_N = 1001;
        int sieve[1001] = {0};
        for(int x=2; x<MAX_N; ++x){ 
            if (sieve[x]) continue; 
            for (int u=2*x; u<MAX_N; u+=x){
                sieve[u]=x;
            } 
        }
        vector<int> primes;
        for(int i=2; i<MAX_N; ++i){
            if(!sieve[i]) primes.push_back(i);
        }

        int n=(int)nums.size();
        for(int i=0; i<n; ++i){
            int prev = (i>0 ? nums[i-1] : 0);
            if(prev>=nums[i]) return false;

            int l=0, r=(int)primes.size()-1;
            while(l<=r){
                int m=l+(r-l)/2;
                if(primes[m] < nums[i]-prev){
                    l=m+1;
                } else {
                    r=m-1;
                }
            }
            nums[i] -= (l>0 ? primes[l-1] : 0);
        }
        return true;
    }
};

// can precompute primes using sieve in O(n*log(log(n)))
// create a sieve arr of size N with all elements = 0
// for i=2; i<N; ++i, if sieve[i] continue
// else set all multiples of i
// for u=i*2; u<N; u+=i, sieve[u] = i
// if sieve[i] = 0, i is a prime number
// if sieve[i] = k, i is NOT prime and k is ONE of its prime factors

// can binary search for first prime <= nums[i]-nums[i-1]

// start at index [0], subtract max possible prime
// move to index [1], subtract max possible prime that keeps [1] > [0]
// continue for all [i]
// at any [i], if [i-1] >= [i], return false
// return true