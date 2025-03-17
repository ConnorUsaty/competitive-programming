class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>> i_list; // {val, idx}
        i_list.push_back({nums[0],0});

        int ans = 0;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]<i_list.back().first){
                i_list.push_back({nums[i],i});
            }
            else{
                int l=0, r=i_list.size()-1;
                while(l<=r){
                    int m = l+(r-l)/2;
                    if(i_list[m].first>nums[i]){
                        l = m+1;
                    } else {
                        r = m-1;
                    }
                }
                ans = max(ans, i-i_list[l].second);
            }
        }
        return ans;
    }
};

// O(nlogn) time, O(n) space

// add to possible i list if < i_list.back(), else always better to choose earlier element
// if not adding to i_list, binary search to find first element <= curr
// calculate diff of indexes i-j, update ans = max(ans, diff);



class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> indicesStack;

        // Fill the stack with indices in increasing order of their values
        for (int i = 0; i < n; i++) {
            if (indicesStack.empty() || nums[indicesStack.top()] > nums[i]) {
                indicesStack.push(i);
            }
        }

        int maxWidth = 0;

        // Traverse the array from the end to the start
        for (int j = n - 1; j >= 0; j--) {
            while (!indicesStack.empty() &&
                    nums[indicesStack.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - indicesStack.top());
                // Pop the index since it's already processed
                indicesStack.pop();
            }
        }

        return maxWidth;
    }
};

// O(n) time, O(n) space

// These solutions are due to the observation that it is always better to take the widest gap, and therefore only need to track a strictly decreasing sequence