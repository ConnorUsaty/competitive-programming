class Solution {
public:
    string clearStars(string s) {
        int n=static_cast<int>(s.size());

        int mn_i = 26;
        vector<vector<int>> cnt(26);
        for(int i=0; i<n; ++i){
            if(s[i]=='*'){
                s[cnt[mn_i].back()] = '#';
                cnt[mn_i].pop_back();
                while(mn_i<26 && cnt[mn_i].size()==0){
                    mn_i++;
                }
            }
            else{
                cnt[s[i]-'a'].push_back(i);
                if(s[i]-'a' < mn_i){
                    mn_i = s[i]-'a';
                }
            }
        }

        string ans = "";
        for(int i=0; i<n; ++i){
            if(s[i]>='a' && s[i]<='z'){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

// always best to remove most recent occurence of min char
// therefore just track all indexes
// whenever we hit a '*' mark the most recent min char as seen with '#'
// then loop over s a second time to build the ans string skipping all '*' and '#'

// O(n) time, O(n) space