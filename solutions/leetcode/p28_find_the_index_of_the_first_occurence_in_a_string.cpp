class Solution {
public:
    int strStr(string haystack, string needle) {
        // use KMP algorithm O(m+n)
        int m = (int)needle.size();
        int n = (int)haystack.size();
        vector<int> pi(m, 0);

        // create pi table O(m)
        for(int i=1;i<m;++i){
            int j=pi[i-1];
            while(j>0 && needle[j]!=needle[i]) j = pi[j-1];
            if(j==0 && needle[0]!=needle[i]) pi[i]=0;
            else pi[i]=j+1;
        }

        // use pi table for search O(n)
        int j=0;
        for(int i=0;i<n;++i){
            while(j>0 && haystack[i]!=needle[j]) j = pi[j-1];
            if(haystack[i]==needle[j]) j++;
            if(j==m) return i-j+1;
        }

        return -1;
    }
};