class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed[0]==0){
            if((flowerbed.size()>=2 && flowerbed[1]==0) || (flowerbed.size()==1)){
                flowerbed[0] = 1;
                n--; 
            }
        }
        for(int i=1;i<flowerbed.size()-1;++i){
            if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                flowerbed[i] = 1;
                n--;
            }
        }
        if(flowerbed[flowerbed.size()-1]==0 && flowerbed[flowerbed.size()-2]==0){
            n--;
        }
        return n<=0;
    }
};

// always best to place flowers as early as possible, there greedy approach
// seperate checks for first / last index so the condition does not have to be checked an extra n-2 times inside loop
// change flowerbed[i] to 1 to indicate flower being placed and to not reuse spots -> similar to floodfill / dfs problems dont want to overcount