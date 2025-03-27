class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50,
                                40,   10,  9,   5,   4,   1};
        vector<string> symbols = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                    "XL", "X",  "IX", "V",  "IV", "I"};
        string roman;
        for (int i = 0; i < values.size() && num > 0; i++) {
            while (values[i] <= num) {
                num -= values[i];
                roman += symbols[i];
            }
        }
        return roman;
    }
};

// just add the largest unique denomination that can fit at each time
// denominations follow the 1, 9, 5, 4, 1, etc. pattern