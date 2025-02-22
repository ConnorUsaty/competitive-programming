class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        return ((s.count(0)) ? (int)s.size()-1 : (int)s.size());
    }
};

// ans is number of unique non-zero elements
// to get num of unique elements can throw everything into set
// then -1 from set size if 0 is in the set
// therefore getting the num of unique non-zero elements