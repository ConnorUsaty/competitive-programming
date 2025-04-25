class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        queue<int> mx_idx;
        long long ans=0;
        for(int i=0; i<n; ++i){
            if(nums[i]==mx){
                mx_idx.push(i);
                while((int)mx_idx.size()>k){
                    mx_idx.pop();
                }
            }
            if((int)mx_idx.size()==k){
                ans += (1 + mx_idx.front());
            }
        }
        return ans;
    }
};

// whenever the window is valid it is bounded by the last k occurences of the max element
// specficially it is bounded by the kth last max element
// we can just add all the subarrays before that kth last element for each valid window