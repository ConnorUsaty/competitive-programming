class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int ans=-1;

        while(l<r){
            ans = max(ans, (min(height[l],height[r])*(r-l)));
            if(height[l]<height[r]){
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};


// two ptr similar to trapping rain water
// at each iteration calculate area of rect and check if > curr ans
// then move the smaller of the two heights inwards