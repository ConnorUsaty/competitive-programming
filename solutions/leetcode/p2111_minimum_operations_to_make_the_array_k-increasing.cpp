class Solution {
private:
    int lis(vector<int>& arr, int i, int k) {
        vector<int> seq;
        int m = 0;
        for(; i<arr.size(); i+=k) {
            m++;
            if(seq.empty() || arr[i]>=seq.back()) {
                seq.push_back(arr[i]);
            } else {
                // replace first element > arr[i]
                auto it = std::upper_bound(seq.begin(), seq.end(), arr[i]);
                int idx = std::distance(seq.begin(), it);
                seq[idx] = arr[i];
            }
        }
        return static_cast<int>(m - seq.size());
    }

public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans = 0;
        for(int i=0; i<k; ++i) {
            ans += lis(arr, i, k);
        }
        return ans;
    }
};

// m = n/k
// O(k*mlogm) time -> find LIS for k seq of size m
// O(m) space -> LIS

// std::upper_bound(begin, end, target) returns it to first element > target
// std::distance(begin, it) returns distance or idx of iterators