class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        int n=(int)d.size();

        int cnt[100] = {0};
        int ans=0;
        for(int i=0; i<n; ++i){
            int a=d[i][0], b=d[i][1];
            if(a>b) swap(a,b);
            ans += cnt[a*10 + b]++;
        }
        return ans;
    }
};

// another pairs question, can use array or hashset or hashmap to check for seen values in O(1)
// to account for swapping and a=b scenarios, use hash of a*10+b with a<=b