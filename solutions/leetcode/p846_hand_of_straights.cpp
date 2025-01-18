class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;

        // ordered map -> O(nlogn) to fill
        map<int,int> cnt;
        for(const int& n : hand) cnt[n]++;

        // O(n)
        for(auto it : cnt){
            // if we have alr dealt with element
            if(it.second==0) continue;
            // is start of sequence, check if sequence possible
            while(cnt[it.first]){
                for(int i=0; i<groupSize; ++i){
                    if(--cnt[it.first+i]<0) return false;
                }
            }
        }
        return true;
    }
};

// O(nlogn + n) time
// O(n) space
