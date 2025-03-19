class Solution {
public:
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }

        string ans_str = "";
        int grp_idx = -1;
        while(num > 0){
            string grp_str = "";
            int grp = num % 1000;
            num /= 1000;
            grp_idx++;
            if(grp==0) continue;

            if(grp >= 100){
                grp_str += ones[grp/100] + " Hundred ";
                grp %= 100;
            }
            if(grp>=20){
                grp_str += tens[grp/10] + " ";
                grp %= 10;
            }
            if(grp>0){
                grp_str += ones[grp] + " ";
            }
            grp_str += groups[grp_idx] + " ";
            ans_str = grp_str + ans_str;
        }
        while(ans_str.size()>0 && ans_str[ans_str.size()-1]==' '){
            ans_str.pop_back();
        }
        return ans_str;
    }

private:
    const vector<string> ones = {
        "",
        "One",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine",
        "Ten",
        "Eleven",
        "Twelve",
        "Thirteen",
        "Fourteen",
        "Fifteen",
        "Sixteen",
        "Seventeen",
        "Eighteen",
        "Nineteen"
    };
    const vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const vector<string> groups = {"", "Thousand", "Million", "Billion"};
};

// clarify inputs, outputs, constraints
// walk through example
// come up with and evaluate solutions -> involves actually listing out steps required / pseudo code
// code solution
// consider edge cases and refer to constraints
// walk through example / test with solution
// run / submit code

// group name, hundreds name, 0-19 needs specific mapping, 20-99 can be decomposed into tens and ones digits