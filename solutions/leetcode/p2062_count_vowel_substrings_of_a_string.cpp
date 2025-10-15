class Solution {
private:
    bool insert_vowel(string& word, int i, int& k, int& unq_vowels, std::array<int,5>& vowel_cnt) {
        unordered_map<char,int> vowel_mp = { 
            {'a',0}, {'e',1}, {'i',2}, {'o',3}, {'u',4}
        };
        auto it = vowel_mp.find(word[i]);
        if(it == vowel_mp.end()) return false;

        if(++vowel_cnt[it->second] == 1) unq_vowels++;
        while(unq_vowels == 5) {
            if(vowel_mp.find(word[k])!=vowel_mp.end() && --vowel_cnt[vowel_mp[word[k]]] == 0)
                unq_vowels--;
            k++;
        }
        return true;
    }

public:
    int countVowelSubstrings(string word) {
        int unq_vowels = 0, ans = 0, l = 0, k = 0;
        std::array<int,5> vowel_cnt;
        std::fill(vowel_cnt.begin(), vowel_cnt.end(), 0);

        for(int r=0; r<word.size(); ++r) {
            if (insert_vowel(word, r, k, unq_vowels, vowel_cnt)) {
                ans += k-l;
            } else {
                unq_vowels = 0;
                k = l = r + 1;
                std::fill(vowel_cnt.begin(), vowel_cnt.end(), 0);
            }
        }
        return ans;
    }
};

// whenever we hit a constanant move l = r+1
// we cannot have a substring with it in it
// keep cnt of each vowel and cnt of total vowels

// we are left bound by the last letter we req to have unq_vowels == 5
// everything to the left of that is extra
// at each r we can calculate all possible end pts of array to achieve O(n) time, O(1) space