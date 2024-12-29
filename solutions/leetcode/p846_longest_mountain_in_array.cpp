class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = (int)arr.size();
        int up=0, down=0, ans=0;
        
        for(int i=0; i<n-1; ++i){
            if(arr[i]<arr[i+1]){
                // down can only go up if up > 0
                if(down>0){
                    // therefore must be switching from down to up
                    ans = max(ans, up+down+1);
                    up = 0;
                    down = 0;
                }
                up++;
            } 
            else if(arr[i]>arr[i+1] && up>0){
                down++;
            }
            else {
                if(down>0) ans = max(ans, up+down+1);
                up=0;
                down=0;
            }
        }
        if(down>0) ans = max(ans, up+down+1);
        return ans;
    }
};

// can simply keep track of length of most recent up / down sequences, then ans = max(ans, up+down+1) at each switch from down to up
// need to check once more outside of loop to catch any mountains that had an ongoing downwards trend into last element of arr
// also need to check before resetting counts when entering an element = to the prev element
