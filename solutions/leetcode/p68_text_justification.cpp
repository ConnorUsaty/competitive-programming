class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int curr_len=0;
        vector<string> curr_row;
        vector<string> ans;

        for(string s : words){
            if(curr_len+s.length()<=maxWidth){
                curr_row.push_back(s);
                curr_len+=s.length()+1;
            }
            else {
                curr_len-=1;
                int total_extra_spaces = maxWidth-curr_len;
                int extra_extra_spaces=0, normal_extra_spaces=0;
                if (curr_row.size()>1){
                    extra_extra_spaces = total_extra_spaces % (curr_row.size()-1);
                    normal_extra_spaces = total_extra_spaces / (curr_row.size()-1);
                } else {
                    normal_extra_spaces = total_extra_spaces-1;
                }
                string w = "";
                for(string t : curr_row){
                    w += t;
                    if (w.length()==maxWidth) continue;
                    w += ' ';
                    if (extra_extra_spaces-- > 0) w+= ' ';
                    int temp = normal_extra_spaces;
                    while(temp-- > 0) w+= ' ';
                }
                ans.push_back(w);
                curr_row = {s};
                curr_len = s.length()+1;
            }
        }

        // add in left justified final row
        curr_len-=1;
        int total_extra_spaces = maxWidth-curr_len;
        string w = "";
        for(string t : curr_row){
            w += t;
            if (w.length()==maxWidth-total_extra_spaces) continue;
            w += ' ';
        }
        int temp = total_extra_spaces;
        while(temp-- > 0) w+= ' ';
        ans.push_back(w);
        return ans;
    }
};

// its ok to hard code specific edge cases if they can't be included in the general solution
// remember to account for edge cases