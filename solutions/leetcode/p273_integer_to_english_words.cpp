class Solution {
public:
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }

        int grp_idx = -1;
        string ans = "";

        while(num > 0){
            string grp_ans = "";
            int curr = num % 1000;
            num /= 1000;
            grp_idx++;
            if(curr==0) continue;

            if(curr >= 100){
                grp_ans += ones[curr / 100] + " Hundred ";
                curr %= 100;
            }
            if(curr>=20){
                grp_ans += tens[curr/10] + " ";
                curr %= 10;
            }
            if(curr>0){
                grp_ans += ones[curr] + " ";
            }
            grp_ans += groups[grp_idx] + " ";
            ans = grp_ans + ans;
        }

        while(ans.size()>=1 && ans[ans.size()-1]==' '){
            ans.pop_back();
        }

        return ans;
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

// process in groups of three to append group labe, i.e. "Thousand"
// Need unique mapping for 1 through 19
// Can split ones and tens dig from 20 to 99
// Remember to consider edge cases such as num or curr == 0