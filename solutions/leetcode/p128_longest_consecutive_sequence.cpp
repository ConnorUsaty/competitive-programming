class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int curr = 0;
        int ans = 0;
        for(int n : s){
            if(s.find(n-1)!=s.end()){
                continue;
            }
            curr = 1;
            while(s.find(n+1)!=s.end()){
                curr++;
                n++;
            }
            ans = max(curr,ans);
        }
        return ans;
    }
};

// Put all nums in set
// iterate over set
// for each element check if its a start of a sequence
// if it is get length of sequence and update ans
