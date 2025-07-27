class Solution {
private:
    void build_prime_mp(const vector<int>& nums, unordered_map<int, vector<int>>& prime_mp){
        int n = (int)nums.size();
        for(int i=0; i<n; ++i){
            if(nums[i]<=1) continue;

            int m = nums[i];
            for(int j=2; j*j <=m; ++j){
                if(m % j==0){
                    prime_mp[j].push_back(i);
                    while(m%j==0) m /= j;
                }
            }
            if(m>1) prime_mp[m].push_back(i);
        }
    }

    bool is_prime(int x){
        if(x<=1) return false;
        if(x==2) return true;
        if(x%2==0) return false;

        for(int i=3; i*i<=x; i+=2){
            if(x%i==0) return false;
        }
        return true;
    }

    int bfs(const vector<int>& nums, unordered_map<int, vector<int>>& prime_mp){
        int n = (int)nums.size();
        queue<int> q;
        vector<bool> visited(n, false);
        unordered_set<int> used_primes;

        q.push(0);
        visited[0] = true;
        int ans = 0;

        while(!q.empty()){
            int s = q.size();

            for(int i=0; i<s; ++i){
                int curr = q.front();
                q.pop();

                if(curr == n-1) return ans;

                if(curr>0 && !visited[curr-1]){
                    q.push(curr-1);
                    visited[curr-1] = true;
                }
                if(!visited[curr+1]){
                    q.push(curr+1);
                    visited[curr+1] = true;
                }

                int val = nums[curr];
                if(is_prime(val) && used_primes.find(val) == used_primes.end()){
                    used_primes.insert(val);

                    for(auto idx : prime_mp[val]){
                        if(!visited[idx]){
                            q.push(idx);
                            visited[idx] = true;
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
    
public:
    int minJumps(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 1) return 0;

        unordered_map<int, vector<int>> prime_mp;
        build_prime_mp(nums, prime_mp);

        return bfs(nums, prime_mp);
    }
};

// if nums[i] is prime we can jump to any [j] % nums[i] == 0

// make into a graph then bfs
// edges = i-1, i+1, edges added via primes