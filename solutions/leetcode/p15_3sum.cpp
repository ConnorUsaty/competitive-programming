class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // O(nlogn)

        // O(n^2)
        for(int i=0;i<n-2;++i){
            if(nums[i]>0) break; // no more possible solutions
            int l=i+1, r=n-1;
            while(l<r){
                int s = nums[i]+nums[l]+nums[r];
                if(s>0){
                    r--;
                } else if(s<0){
                    l++;
                }
                else{
                    ans.push_back({nums[i],nums[l],nums[r]});
                    // avoid duplicate answers
                    while(l<n-1 && nums[l]==nums[l+1]) l++;
                    while(r>0 && nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                }
            }
            // avoid duplicate answers
            while(i<n-3 && nums[i]==nums[i+1]) i++;
        }

        return ans;
    }
};

// can perform twoSum with each index as the third element, resulting in O(n^2)
// cannot use hashmap twoSum as it results in duplicate triplet pairs
// must use two ptr twoSum to skip over any possible duplicate triplet pairs, resulting in + O(nlogn) from sorting
// the while loops that prevent duplicates must be properly placed only after the usage of the element or else valid answers will be skipped
