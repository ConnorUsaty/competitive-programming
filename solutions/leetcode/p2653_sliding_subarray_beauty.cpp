class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int cnt[101] = {0}; // offset + 50, i.e. cnt[0] = cnt of -50

        vector<int> ans((int)nums.size()-k+1, 0);
        for(int i=0; i<(int)nums.size(); ++i){
            cnt[nums[i]+50]++;
            if(i-k+1>=0){
                int seen=0;
                for(int j=0; j<51; ++j){
                    seen += cnt[j];
                    if(seen>=x){
                        ans[i-k+1]=j-50;
                        break;
                    }
                }
                cnt[nums[i-k+1]+50]--;
            }
        }
        return ans;
    }
};

// subarray of size k
// ans[i] = xth smallest int in subarray, 0 if < x neg ints

// maintain cnt of everything in window
// since nums[i] only ranges from -50 to 50
// we can find xth smallest int in O(50) = O(1) time technically

// therefore O(n) time
// O(1) space, regardless of input we are making a cnt array of size 101