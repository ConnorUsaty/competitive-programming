using pii = pair<int,int>;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n=static_cast<int>(nums.size());

        vector<pii> mx(n);
        vector<pii> mn(n);
        mx[0] = {nums[0], 0};
        mn[0] = {nums[0], 0};
        for(int i=1; i<n; ++i){
            if(nums[i]>mx[i-1].first){
                mx[i] = {nums[i], i};
            } else {
                mx[i] = mx[i-1];
            }
            if(nums[i]<mn[i-1].first){
                mn[i] = {nums[i], i};
            } else {
                mn[i] = mn[i-1];
            }
        }

        for(int i=n-1; i>=indexDifference; --i){
            int idx = i-indexDifference;
            if(abs(nums[i]-mx[idx].first) >= valueDifference){
                return vector<int>{mx[idx].second, i};
            }
            if(abs(nums[i]-mn[idx].first) >= valueDifference){
                return vector<int>{mn[idx].second, i};
            }
        }
        return vector<int>{-1, -1};
    }
};

// vector<int> mx where mx[i] is the highest value seen up to and including nums[i]