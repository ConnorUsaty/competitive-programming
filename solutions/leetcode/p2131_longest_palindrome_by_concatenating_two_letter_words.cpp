class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> seen;
        int ans=0;
        for(auto& w : words){
            string reversed(w.rbegin(), w.rend());
            if(seen.find(reversed) != seen.end()){
                ans += 4;
                seen[reversed]--;
                if(seen[reversed]==0) seen.erase(reversed);
            }
            else{
                seen[w]++;;
            }
        }

        for(auto& [s, _] : seen){
            string reversed(s.rbegin(), s.rend());
            if(s==reversed){
                ans += 2;
                break;
            }
        }

        return ans;
    }
};

// for any problem where we need to match an element to another element, use a Two Sum hashmap approach

// at each idx i check if reverse(words[i]) has been seen
// if seen, ans +=2, remove from seen
// else add curr to seen
// edge case letters = each other, in that case ans++s