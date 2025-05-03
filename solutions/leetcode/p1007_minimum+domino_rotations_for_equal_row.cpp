class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=(int)tops.size();

        auto check = [&](int t){
            int rot_a=0, rot_b=0;
            for(int i=0; i<n; ++i){
                if(tops[i]!=t && bottoms[i]!=t){
                    return INT_MAX;
                }
                else if(tops[i]!=t && bottoms[i]==t){
                    rot_a++;
                }
                else if(tops[i]==t && bottoms[i]!=t){
                    rot_b++;
                }
            }
            return min(rot_a, rot_b);
        };
        
        int ans = min((int)check(tops[0]), (int)check(bottoms[0]));
        return (ans==INT_MAX ? -1 : ans);
    }
};