using pii = pair<int,int>;

class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,pii> mp;

        int mx_cnt = -1, mn_n = INT_MAX;
        for(int const & n : nums){
            auto it = mp.find(n%space);
            if(it==mp.end()){
                mp[n%space] = {n,1};
                it = mp.find(n%space);
            }else{
                it->second.first = min(it->second.first, n);
                it->second.second++;
            }

            if(it->second.second>mx_cnt || it->second.second==mx_cnt && it->second.first<mn_n){
                mx_cnt = it->second.second;
                mn_n = it->second.first;
            }
        }
        return mn_n;
    }
};

// map where key is % space, val is {min, cnt}
// return min of max cnt