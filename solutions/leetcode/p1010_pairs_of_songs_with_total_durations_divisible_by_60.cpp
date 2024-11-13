class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> cnt; // store count of vals % 60 seen
        int ans=0;

        for(const int& n : time){
            int diff = (60-n%60==60)?0:60-n%60;
            if (cnt.find(diff) != cnt.end()) ans += cnt[diff];
            cnt[n%60]++;
        }

        return ans;
    }
};

// Since we have small constraints for keys a further optimization would be using an array for O(1) access