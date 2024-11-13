class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> cnt;
        for(const string& w : words) cnt[w]++;

        vector<vector<string>> freq(words.size()+1);
        for(const auto& it : cnt){
            freq[it.second].push_back(it.first);
        }

        vector<string> ans;
        for(int i=words.size();i>=0 && ans.size()<k;--i){
            if(freq[i].empty()) continue;
            sort(freq[i].begin(), freq[i].end());
            for(int j=0;j<freq[i].size() && ans.size()<k;++j) ans.push_back(freq[i][j]);
        }

        return ans;
    }
};

// Solution to top k frequent elements implemented with slight variation
// Optimal solution since words also have to be sorted is to use pq with custom comparator function