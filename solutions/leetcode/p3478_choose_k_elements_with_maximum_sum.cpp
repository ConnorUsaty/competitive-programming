class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=(int)nums1.size();

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(),
            [&](const int i, int j){
                return nums1[i]<nums1[j];
            }
        );

        auto cmp = [&](const int i, const int j){
            return nums2[i]>nums2[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp); // key = min nums2 val
        pq.push(idx[0]);
        
        vector<long long> ans(n, 0);
        long long curr = nums2[idx[0]];
        for(int i=1; i<n; ++i){
            if (nums1[idx[i]] == nums1[idx[i-1]]){
                ans[idx[i]] = ans[idx[i-1]];
            } else {
                ans[idx[i]] = curr;
            }
            int j = idx[i];

            if(pq.size() < k){
                pq.push(j);
                curr += nums2[j];
            }
            else if(!pq.empty() && nums2[pq.top()]<nums2[j]){
                curr -= nums2[pq.top()];
                pq.pop();
                pq.push(j);
                curr += nums2[j];
            }
        }
        return ans;
    }
};

// process elements from smallest nums1 val to highest nums1 val
// therefore after processing any idx [i] we know that nums2[i] will be available for any future indices, because nums1[i] >= nums1[i-1]
// so we just keep track of the current max sum and elements that make it up
// we can track the k MAX elements with a MIN heap, the top element will be the kth highest, therefore if pq.top() is ever lower than the element we are considering pushing we should push it
// then just handle edge case where nums1[idx[i]] == nums1[idx[i-1]], the ans will be the same as ans[idx[i-1]] but still need to update the pq and curr sum

// when using custom cmp for pq, must pass into Template<> and into constructor