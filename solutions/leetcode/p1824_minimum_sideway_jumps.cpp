class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n=(int)obstacles.size();

        vector<int> rock(4, 0);
        int rocks=3;

        int ans=0;
        for(int i=n-1; i>=0; --i){
            if(obstacles[i] && !rock[obstacles[i]]){
                rock[obstacles[i]]=1;
                if(--rocks==0){
                    ans++;
                    i++;
                    for(int j=1; j<4; ++j){
                        if(obstacles[i]!=j && obstacles[i-1]!=j){
                            rock[j]=0;
                            rocks++;
                        }else{
                            rock[j]=1;
                        }
                    }
                }
            }
        }
        return (rock[2] ? ans+1 : ans);
    }
};