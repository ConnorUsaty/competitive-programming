class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        std::vector<int> ans;
        for(const int & spell : spells) {
            auto it = std::lower_bound(potions.begin(), potions.end(), ((success-1)/spell)+1);
            int res = std::distance(it, potions.end());
            ans.push_back(res);
        }
        return ans;
    }
};

// sort potions
// bin search for last  potion > (success / spells)