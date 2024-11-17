class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end());
        vector<bool> ans(candies.size(), false);

        for(int i=0;i<candies.size();++i){
            if(candies[i]+extraCandies >= mx) ans[i]=true;
        }

        return ans;
    }
};


// can use *max_element(vec.begin(), vec.end()) to get max element in vec. Have to dereference with * because it returns an iterator obj