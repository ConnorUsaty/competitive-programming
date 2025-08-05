class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> cnt1;
        for(auto const & w : words1){
            cnt1[w]++;
        }
        unordered_map<string,int> cnt2;
        for(auto const & w : words2){
            cnt2[w]++;
        }

        int ans = 0;
        for(auto it : cnt1){
            if(it.second==1 && cnt2[it.first]==1){
                ans++;
            }
        }
        return ans;
    }
};