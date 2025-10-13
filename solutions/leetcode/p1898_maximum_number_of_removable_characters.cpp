class Solution {
private:
    bool check(string& s, string& p, int m, unordered_map<int,int>& remove_mp) {
        int j=0;
        for(int i=0; i<s.size(); ++i) {
            auto it = remove_mp.find(i);
            if(s[i]==p[j] && (it==remove_mp.end() || it->second>=m)) {
                if(++j == p.size()) return true;
            }
        }
        return false;
    }

public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        unordered_map<int,int> remove_mp;
        for(int i=0; i<removable.size(); ++i) remove_mp[removable[i]] = i;

        int l=0, r=removable.size();
        while(l<=r){
            int m=l+(r-l)/2;
            if (check(s, p, m, remove_mp)) {
                l=m+1;
            } else {
                r=m-1;
            }
        }
        return (l==0 ? l : l-1);
    }
};