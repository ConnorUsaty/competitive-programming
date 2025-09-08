class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::vector<std::string> strs;
        strs.reserve(nums.size());
        for(const int & n : nums) {
            strs.emplace_back(to_string(n));
        }
        sort(strs.begin(), strs.end(), [](std::string& a, std::string& b){
            return (a+b > b+a);
        });

        if(strs[0] == "0") return std::string{"0"};

        std::string ans{};
        for(const std::string& s : strs) {
            ans += s;
        }
        return ans;
    }
};

// turn to strings O(n)
// sort w custom comp O(nlogn)
// make ans O(n)
// O(nlogn) time, O(n) space

// always take largest dig at MSB etc
// when there is a tie we need to continue making optimal decision for each option
// until it is no longer a tie