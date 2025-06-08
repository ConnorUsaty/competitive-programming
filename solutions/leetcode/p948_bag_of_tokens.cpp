class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=static_cast<int>(tokens.size());

        sort(tokens.begin(), tokens.end());

        int l=0, r=n-1, score=0, ans=0;
        while(l<=r){
            if(power>=tokens[l]){
                power -= tokens[l++];
                score++;
            }
            else if(score>=1){
                power += tokens[r--];
                score--;
            }
            else{
                break;
            }
            ans = max(ans, score);
        }
        return ans;
    }
};

// it is always best to gain score while losing minimum power
// it is always best to lose score while gaining maximum power

// therefore just sort and 2 ptr