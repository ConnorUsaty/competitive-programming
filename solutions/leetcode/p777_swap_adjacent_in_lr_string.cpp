class Solution {
public:
    bool canTransform(string start, string result) {
        const int n = (int)start.size();

        int r_start=0, l_res=0;
        for(int i=0; i<n; ++i){
            if(start[i]=='L' && r_start) return false;
            if(result[i]=='R' && l_res) return false;

            if(start[i] == result[i]) continue;
            if(start[i]=='R') r_start++;
            else if(start[i]=='L'){
                if(--l_res < 0) return false;
            }
            if(result[i]=='L') l_res++;
            else if(result[i]=='R'){
                if(--r_start < 0) return false;
            }
        }
        return (l_res==0 && r_start==0);
    }
};