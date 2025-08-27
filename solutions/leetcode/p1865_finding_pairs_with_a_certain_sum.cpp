class FindSumPairs {
private:    
    vector<int> nums2_;
    unordered_map<int,int> freq1_;
    unordered_map<int,int> freq2_;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums2_(std::move(nums2)) {
        for(auto& n : nums1) {
            freq1_[n]++;
        }

        for(auto& n : nums2_) {
            freq2_[n]++;
        }
    }
    
    void add(int idx, int val) {
        freq2_[nums2_[idx]]--;
        nums2_[idx] += val;
        freq2_[nums2_[idx]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(auto& [n, freq] : freq1_){
            int diff = tot - n;
            cnt += freq2_[diff] * freq;
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */