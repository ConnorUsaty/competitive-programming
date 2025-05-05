class Solution {
public:
    bool queryString(string s, int n) {
        for(int i=n; i>n/2; --i){
            string b = bitset<32>(i).to_string();
            if(s.find(b.substr(b.find("1"))) == string::npos){
                return false;
            }
        }
        return true;
    }
};

// b.substr(b.find("1")) removes all leading zeros
// if s.find == string::npos, the substr was not found within s
// can pass an integer into a bitset to get it represented as a binary boolean array
// can call bitset.to_string() to get the binary string

// this solution works because n is large but s is small
// so repeatedly searching within s is still fast
// and cutting down the n we have to search for makes a big difference