class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<int,int> cnt1;
        unordered_map<int,int> cnt2;
        for(const char& c : word1) cnt1[c]++;
        for(const char& c : word2) cnt2[c]++;
        int d1 = (int)cnt1.size();
        int d2 = (int)cnt2.size();

        // ensure word1 is the one with more distinct
        if(d1<d2){
            cnt1.swap(cnt2);
            swap(word1, word2);
            swap(d1, d2);
        }
        // now d1 is >= d2 for sure

        if(d1-d2>=3) return false;
        if(d1-d2 == 0){
            // need a swap that keeps them the same
            // swap same char in both
            // swap diff char, freq = 1 in both
            // swap diff char, freq > 1 in both
            bool greater = false, equal = false; // to not recheck same scenario
            for(auto& it : cnt1){
                if(cnt2.find(it.first) != cnt2.end()) return true;
                if(it.second==1 && !equal){
                    for(auto& it2 : cnt2){
                        if(it2.second==1) return true;
                    }
                    equal = true;
                }
                if(it.second>1 && !greater){
                    for(auto& it2 : cnt2){
                        if(it2.second>1) return true;
                    }
                    greater = true;
                }
            }
        }

        if(d1-d2 == 2){
            bool ok = false;
            for(auto& it : cnt1){
                if(it.second==1 && cnt2.find(it.first)==cnt2.end()){
                    ok = true;
                    break;
                }
            }
            if(!ok) return false;
            for(auto& it2 : cnt2){
                if(it2.second>=2 && cnt1.find(it2.first)!=cnt1.end()){
                    return true;
                }
            }
        }

        if(d1-d2 == 1){
            // need 1. a swap that decreases d1 by 1 and keeps d2 the same
            // OR 2. a swap that keeps d1 the same and increases d2 by 1
            // 1. -> can swap any char in w1 with freq = 1 if it exists in w2 and w2 contains a char th
            // 2. -> can swap any char in w1 with freq > 1 if DNE in w2 and w2 contains a c with f>=2
            for(auto& it : cnt1){
                if(it.second==1 && cnt2.find(it.first)!=cnt2.end()){
                    for(auto& it2 : cnt2){
                        if(it.first!=it2.first && it2.second>=2 && cnt1.find(it2.first)!=cnt1.end()) return true;
                    }
                }
                if(it.second==1 && cnt2.find(it.first)==cnt2.end()){
                    for(auto& it2 : cnt2){
                        if(it2.second==1 && cnt1.find(it2.first)!=cnt1.end()) return true;
                    }
                }
                if(it.second>1 && cnt2.find(it.first)==cnt2.end()){
                    for(auto& it2 : cnt2){
                        if(it2.second>=2 && cnt1.find(it2.first)!=cnt1.end()) return true;
                    }
                }
            }
        }
        return false;
    }
};

// diff = abs(distinct in w1 - distinct in w2)
// if diff >=3 -> false
// if diff == 2 -> have to have a char in w1 with freq 1, that does not exist in w2
// if diff == 1 -> have 
// if diff == 0 -> we still have to make a swap


// I broke it into cases and solved each case
// O(n*m)

// can be done much easier by making a double for loop to 26
// for each letter of alphabet check if the swap would make the distincts equal
// O(26^2 + max(m,n))