class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> last;
        for(int i=0;i<nums.size();++i){
            if(last.find(nums[i])!=last.end() && i-last[nums[i]]<=k){
                return true;
            }
            last[nums[i]] = i;
        }
        return false;
    }
};

// can also be treated as sliding window problem
// any problem where you have to check for x within k adjacent elements or a window of k size or within last k elements -> sliding window -> two ptr or deque or prefix sums or cnts
