class NumArray {
private:
    vector<int> p_sum;
    
public:
    NumArray(vector<int>& nums) {
        p_sum.resize(nums.size()+1);
        for(int i=1;i<=nums.size();++i){
            p_sum[i] = nums[i-1];
        }
        for(int i=1;i<=nums.size();++i){
            p_sum[i] += p_sum[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return p_sum[right+1] - p_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// sum over range / subarray should instantly signal sliding window or prefix sum
// single query of range can be done with sliding window, i.e. without storing results in an array
// when its multiple queries answers can be precomputed with a prefix sum array and return in O(1) from there
