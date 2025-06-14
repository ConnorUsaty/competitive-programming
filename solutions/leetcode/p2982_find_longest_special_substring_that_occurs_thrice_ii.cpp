class Solution {
public:
    int maximumLength(string s) {
        int n=static_cast<int>(s.size());
        
        vector<vector<int>> mx(26, vector<int>(3, 0));
        char prev = s[0];
        int len = 1;
        for(int i=1; i<n; ++i){
            if(s[i]==prev){
                len++;
            }
            else{
                mx[prev-'a'][2] = max(mx[prev-'a'][2], len);
                sort(mx[prev-'a'].begin(), mx[prev-'a'].end(), greater<>());
                len = 1;
                prev = s[i];
            }
        }

        mx[prev-'a'][2] = len;
        sort(mx[prev-'a'].begin(), mx[prev-'a'].end(), greater<>());

        int ans=-1;
        for(int i=0; i<26; ++i){
            ans = max(ans, max(mx[i][0]-2, mx[i][2]));
            if(mx[i][0]-1 == mx[i][1] || mx[i][0]-1 == mx[i][1]){
                ans = max(ans, mx[i][0]-1);
            }
            if(mx[i][0]==mx[i][1]){
                ans = max(ans, mx[i][0]-1);
            }
        }
        return (ans>0 ? ans : -1);
    }
};

// track three longest streaks for all lowercase letters 
// then ans = max(max(cnt[i][0]-2, cnt[i][2])) for all i