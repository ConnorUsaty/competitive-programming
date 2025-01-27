// from editorital, modified slightly and converted to c++
// greedy solution:
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;
        for(int i=0;i<s.size();++i) last[s[i]] = i;

        int j=0, anchor=0;
        vector<int> ans;
        for(int i=0; i<s.size(); ++i){
            j = max(j, last[s[i]]);
            if(i==j){
                ans.push_back(j-anchor+1);
                anchor=j+1;
            }
        }
        return ans;
    }
};

// can also be solved as an interval problem in O(n) technically
// since there is at max 26 intervals, one for each char in alphabet, sorting is O(26log(26)) -> O(1)

// this solution ran faster than the above solution on leetcode
// intervals solution:
typedef pair<int,int> pii;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pii> bounds(26, {1e9,-1e9});
        for(int i=0; i<s.size(); ++i){
            bounds[s[i]-'a'].first = min(bounds[s[i]-'a'].first, i);
            bounds[s[i]-'a'].second = max(bounds[s[i]-'a'].second, i);
        }
        sort(bounds.begin(), bounds.end());

        int p_start = 0;
        int p_end = bounds[0].second;
        vector<int> ans;
        for(int i=1; i<26; ++i){
            if(bounds[i].first == 1e9) break;

            if(bounds[i].first < p_end){
                p_end = max(p_end, bounds[i].second);
            }
            else {
                ans.push_back(p_end-p_start+1);
                p_start = bounds[i].first;
                p_end = bounds[i].second;
            }
        }
        // have to account for last interval outside of loop
        ans.push_back(p_end-p_start+1);
        return ans;
    }
};