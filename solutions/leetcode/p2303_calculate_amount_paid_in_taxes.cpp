class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int last = 0;
        double ans = 0.0;
        for(size_t i=0; i<brackets.size(); ++i) {
            int upper = brackets[i][0];
            int percent = brackets[i][1];
            if (income > upper) {
                ans += (upper-last) * (percent/100.0);
            } else {
                ans += (income-last) * (percent/100.0);
                break;
            }
            last = upper;
        }
        return ans;
    }
};