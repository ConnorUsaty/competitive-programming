class Solution {
public:
    int longestDecomposition(string text) {
        const int n = (int)text.size();
        int prev_l=0, l=0, r=n-1, ans=0;
        string curr = "";
        while(l<=r){
            while(l<r && text[l]!=text[r]){
                curr += text[l++];
            }
            if(l==r){
                ans++;
                break;
            }
            curr += text[l];
            if(curr == text.substr(r-curr.size()+1, curr.size())){
                ans += 2;
                r -= curr.size();
                prev_l = l;
                l++;
                curr = "";
            }
            else{
                l++;
            }
        }
        return ans;
    }
};

// have 2 ptrs l and r
// r is init n-1, l is init 0
// while(l<r)
// for each r continue l++ until text[l] == text[r]
// ss_len = l-prev_l+1;
// then if (text.substr(prev_l, ss_len) == text.substr(r-ss_len+1, ss_len))
// ans += 2; r -= ss_len; prev_l = l; l++;

// return ans