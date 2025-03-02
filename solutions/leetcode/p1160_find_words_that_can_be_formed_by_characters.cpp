class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> c_cnt;
        for(const char& c : chars) c_cnt[c]++;
        
        int ans=0;
        for(const string& word : words){
            unordered_map<char,int> t_cnt = c_cnt;
            bool ok = true;
            for(const char& c : word){
                if(--t_cnt[c] < 0){
                    ok = false;
                    break;
                }
            }
            if(ok) ans += (int)word.size();
        }
        return ans;
    }
};

// since constraints are lowercase letters only could have also used an array with ASCII values