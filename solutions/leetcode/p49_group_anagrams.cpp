class Solution {
private:
    string getKey(const string& s){
        int cnt[26] = {0};
        for(const char& c : s){
            cnt[c-'a']++;
        }

        string key = "";
        for(int i=0; i<26; ++i){
            key += to_string(cnt[i]);
            key += '#';
        }
        return key;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;
        for(const string& s : strs){
            string key = getKey(s);
            groups[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(const auto& it : groups){
            ans.push_back(it.second);
        }
        return ans;
    }
};