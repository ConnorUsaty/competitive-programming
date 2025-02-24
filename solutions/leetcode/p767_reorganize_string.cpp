class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> cnt;
        char mx_c;
        int mx_n = 0;
        for(const char& c : s){
            if(++cnt[c]>mx_n){
                mx_n = cnt[c];
                mx_c = c;
            }
        }

        if((mx_n - 1)*2 >= (int)s.size()){
            return "";
        }

        string ans(s.size(), '_');
        int i=0;
        while(cnt[mx_c]-- > 0){
            ans[i] = mx_c;
            i += 2;
        }

        for(auto& it : cnt){
            while(it.second-- > 0){
                i = (i>=(int)s.size()) ? 1 : i;
                ans[i] = it.first;
                i += 2;
            }
        }

        return ans;
    }
};

// cannot use a two ptr swap due to case "baaba", solution for this requires moving a characters in a way that swapping will not due
// instead we can use a greedy algo with the counts of each char
// if the (max count - 1) * 2 >= s.size(), we know re arranging is not possible
// else we can just greedily place the max element first, then place the rest of the elements each 2 idx apart
// have to reset i to 1 once it goes out of bounds (first pass is finished)

// can create string of certain size through -> string s(size, char);