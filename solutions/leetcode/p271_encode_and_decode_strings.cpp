class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for(const string& s : strs) encoded += to_string(s.size()) + '#' + s;
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i=0;
        while(i<(int)s.length()){
            int n=0;
            while(s[i]!='#'){
                n *= 10;
                n += s[i]-'0'; // convert from char to int
                i++;
            }
            decoded.push_back(s.substr(i+1, n));
            i += 1+n;
        }
        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

// Can encode strings by putting string length then delimiter before string
// When decoding read string until hitting delimiter to get string length
// Then append next n chars (str length) as a str to output
// Then skip ahead n+1 chars (over the string and delimiter) to the start of the next str encoding
// Repeat process to get str length, etc.
// Remember to reset n each loop
