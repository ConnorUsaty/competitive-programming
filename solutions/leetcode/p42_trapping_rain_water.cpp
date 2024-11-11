class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r=height.size()-1;
        
        int l_max=-1,r_max=-1,ans=0;
        while(l<r){
            if(height[l]<height[r]){
                l_max=max(l_max,height[l]);
                ans += l_max-height[l++];
            }
            else {
                r_max=max(r_max,height[r]);
                ans += r_max-height[r--];
            }
        }
        return ans;
    }
};

// Two pointer move smaller pointer inwards -> This is because if we know the other wall is >= wall moving then we know any water up to smaller wall is contained
// Then we can simply add the amount of water stored at that index which is the current max of the side were moving - the amount of current index taken up by wall