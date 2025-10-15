class Solution {
public:
    vector<int> maxUpgrades(vector<int>& count, vector<int>& upgrade, vector<int>& sell, vector<int>& money) {
        const int n = static_cast<int>(count.size());

        vector<int> ans;
        ans.reserve(n);
        for (int i=0; i<n; ++i) {
            long long c = count[i], u = upgrade[i], s = sell[i], m = money[i];
            ans.emplace_back(min(c, (c * s + m) / (u + s)));
        }
        return ans;
    }
};

// each [i] is a different data center
// return vector<int> where each [i] is the MAX num of servers that can be upgraded for data center i

// binary search on ans for each data center
// O(nlogn)

// can get O(n) if we perform checks in O(1)
// the only faster check than bin search is math or precompute