class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = (int)arr.size();
        vector<pair<int,int>> mp(n+1);
        unordered_map<int,int> cnt; // key = i , OR j + arr.size()
        for(int i=0; i<mat.size(); ++i){
            for(int j=0; j<mat[0].size(); ++j){
                mp[mat[i][j]] = {i,j};
            }
        }
        for(int k=0; k<n; ++k){
            auto [i, j] = mp[arr[k]];
            if(++cnt[i]==(int)mat[0].size()) return k;
            if(++cnt[j+mat.size()]==(int)mat.size()) return k;
        }
        return -1;
    }
};