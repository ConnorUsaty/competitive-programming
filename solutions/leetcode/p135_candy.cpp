class Solution {
public:
    int candy(vector<int>& ratings) {
        int up, down, ans=ratings.size();

        int i=1;
        while(i<ratings.size()){
            if(ratings[i]==ratings[i-1]){
                i++;
                continue;
            }
            up=0;
            while(ratings[i]>ratings[i-1]){
                ans += ++up;
                if(++i==ratings.size()) return ans;
            }
            down=0;
            while(i<ratings.size() && ratings[i]<ratings[i-1]){
                ans += ++down;
                i++;
            }
            ans -= min(up,down);
        }
        return ans;
    }
};

// Have to give all children >= 1 candy, start ans=n;
// Then each child must have more candy than neighbours with lower rating
// Can find up/down trends and add them to the sum then minus the excess if we find a valley in between

// Second loop must have i<ratings.size() as cond and not return, because we must minus off excess if we enter both loops