class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_element=1e9;
        int max_diff=0;

        for (const int& n : prices) {
            min_element = min(min_element, n);
            max_diff = max(max_diff, n-min_element);
        }

        return max_diff;
    }
};

// Can just use greedy checking at each index if its a better buy or sell point
// const int& improves memory / speed slightly in for loop -> & can be used when deep copy not required, const can be used when read only required, i.e. no modifying of val n