class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int carry = 0;
        int n1 = num1.length(), n2 = num2.length();
        
        for (int i = 0; i < max(n1, n2); ++i) {
            int d1 = (n1 - 1 - i >= 0) ? num1[n1 - 1 - i] - '0' : 0;
            int d2 = (n2 - 1 - i >= 0) ? num2[n2 - 1 - i] - '0' : 0;
            int sum = d1 + d2 + carry;
            carry = sum / 10;
            ans += (sum%10 + '0');
        }

        if (carry) {
            ans += (carry + '0');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// way faster to do ans += (sum%10 + '0') and reverse later than to do:
// ans = to_string(sum%10) + ans, and not have to reverse later