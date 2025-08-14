class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> cnt;
        for(auto& a : arr){
            cnt[a]++;
        }

        vector<int> freqs;
        freqs.reserve(cnt.size());
        for(auto& [a, freq] : cnt){
            freqs.emplace_back(freq);
        }
        sort(freqs.begin(), freqs.end(), std::greater<>());

        int ans = 0, n = arr.size(), m = (n+1)/2;
        for(int i=0; i<freqs.size(); ++i){
            ans++;
            n -= freqs[i];
            if(n<=m) break;
        }
        return ans;
    }
};