class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> q_idx;
        vector<int> cnt(26,0);
        for(int i=0; i<(int)s.size(); ++i){
            char c = s[i];
            if (c!='?'){
                cnt[c-'a']++;
            } else {
                q_idx.push_back(i);
            }
        }

        int mn=INT_MAX, mn_idx=-1;
        vector<int> chosen(26,0);
        for(auto const & idx : q_idx){
            for(int i=0; i<26; ++i){
                if(cnt[i]<mn){
                    mn=cnt[i];
                    mn_idx=i;
                }
            }
            chosen[mn_idx]++;
            cnt[mn_idx]++;
            mn=INT_MAX;
        }

        int curr=0;
        for(auto const & idx : q_idx){
            while(chosen[curr]<=0){
                curr++;
            }
            s[idx] = static_cast<char>(curr+'a');
            chosen[curr]--;
        }
        return s;


    }
};


// the best choice is always going to be a character with the lowest count BUT we have to account for a scenario where we have to choose i.e. B and later A, since we have to choose both anyways the A should be first
// thats why we need to make our choices first then loop a second time and optimally place our choices in