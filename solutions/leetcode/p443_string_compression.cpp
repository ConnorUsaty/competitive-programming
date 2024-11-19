class Solution {
public:
    int compress(vector<char>& chars) {
        char last = chars[0];
        int cnt=0, i=0;

        for(const char c : chars){
            if(c!=last){
                chars[i++]=last;
                if(cnt>1) {
                    string cnt_str = to_string(cnt);
                    for(const char& c2 : cnt_str) chars[i++]=c2;
                }
                last = c;
                cnt = 1;
            }
            else{
                cnt++;
            }
        }
        // add in last group
        chars[i++]=last;
        if(cnt>1) {
            string cnt_str = to_string(cnt);
            for(const char& c2 : cnt_str) chars[i++]=c2;
        }
        return i;
    }
};


// when looping and adding after switch always have to add last element outside of loop
// can use std::to_string to convert int to str format in c++