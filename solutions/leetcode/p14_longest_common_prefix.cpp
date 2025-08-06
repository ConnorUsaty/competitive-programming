class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int n = (int)strs.size();

        std::string pre = strs[0];
        for(int i=1; i<n; ++i){
            if(pre == "") return pre;

            if(strs[i].size() < pre.size()){
                pre = pre.substr(0, strs[i].size());
            }

            for(int j=0; j<pre.size(); ++j){
                if(pre[j] == strs[i][j]) continue;
                else {
                    pre = pre.substr(0, j);
                    break;
                }
            }
        }

        return pre;
    }
};