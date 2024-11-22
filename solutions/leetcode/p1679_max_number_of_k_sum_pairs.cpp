class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> cnt;
        int ans=0;

        for(const int& n : nums){
            int diff = k-n;
            if(cnt.find(diff)!=cnt.end() && cnt[diff]>0){
                cnt[diff]--;
                ans++;
            }
            else {
                cnt[n]++;
            }
        }
        return ans;
    }
};

// similar to two sum
// keep track of cnt of all seen and unused elements
// if we have an unused target diff available, use it to make a pair and increment answer
// O(n) time and space