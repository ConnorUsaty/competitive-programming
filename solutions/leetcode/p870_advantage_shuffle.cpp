class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=(int)nums1.size();

        sort(nums1.begin(), nums1.end());
        vector<int> order2(n);
        iota(order2.begin(), order2.end(), 0);
        sort(order2.begin(), order2.end(), [&nums2](int i, int j){
            return nums2[i]<nums2[j];
        });

        int l=0, r=n-1;
        vector<int> ans(n);
        for(int i=n-1; i>=0; --i){
            if(nums1[r]>nums2[order2[i]]){
                ans[order2[i]]=nums1[r--];
            }else{
                ans[order2[i]]=nums1[l++];
            }
        }
        return ans;
    }
};

// get sorted order of both
// start at max of both
// if order1[l] > order2[i], ans[i] = order1[l] and l++
// else if order1[l] <= order2[i], ans[i] = order1[r] and r--