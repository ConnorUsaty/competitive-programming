using ll = long long;

class Solution {
public:
    vector<ll> getDistances(vector<int>& arr) {
        int n=(int)arr.size();
    
        vector<ll> ans(n);
        unordered_map<int, vector<ll>> pre_mp;
        for(int i=0; i<n; ++i){
            if(pre_mp.find(arr[i]) != pre_mp.end()){
                pre_mp[arr[i]][0] += (i - pre_mp[arr[i]][1])*pre_mp[arr[i]][2];
                pre_mp[arr[i]][1] = i;
                pre_mp[arr[i]][2]++;
                ans[i] += pre_mp[arr[i]][0];
            }
            else{
                pre_mp[arr[i]] = {0, 1LL*i, 1};
            }
        }

        unordered_map<int, vector<ll>> suf_mp;
        for(int i=0; i<n; ++i){
            if(suf_mp.find(arr[n-1-i]) != suf_mp.end()){
                suf_mp[arr[n-1-i]][0] += (suf_mp[arr[n-1-i]][1] - (n-1-i))*suf_mp[arr[n-1-i]][2];
                suf_mp[arr[n-1-i]][1] = n-1-i;
                suf_mp[arr[n-1-i]][2]++;
                ans[n-1-i] += suf_mp[arr[n-1-i]][0];
            }
            else{
                suf_mp[arr[n-1-i]] = {0, 1LL*n-1-i, 1};
            }
        }

        return ans;
    }
};

// pre / suf fix sums
// keep track of cnt and last seen
// when we see another add cnt*last to ans for that number


// while tuples are nice for unpacking we cannot use [i] on tuples
// have to use set::get<i>(tuple);
// tuples are mutable in c++