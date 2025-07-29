class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        const int n = (int)nums.size();

        vector<int> s_mx(n, 0);
        s_mx[n-1] = nums[n-1];
        for(int i=n-2; i>=0; --i){
            s_mx[i] = s_mx[i+1] | nums[i];
        }

        vector<int> ans;
        vector<int> cnt(32, 0);
        int l = 0, curr = 0;
        for(int r=0; r<n; ++r){
            curr |= nums[r];
            
            int m = nums[r];
            int shft = 0;
            while(m){
                if(m&1){
                    ++cnt[shft];
                }
                m >>= 1;
                shft++;
            }

            while(l<=r && curr==s_mx[l]){
                ans.push_back(r-l+1);
                m = nums[l++];
                shft = 0;
                while(m){
                    if(m&1){
                        if(--cnt[shft]==0){
                            curr ^= (1 << shft);
                        }
                    }
                    m >>= 1;
                    shft++;
                }
            }
        }

        return ans;
    }
};

// count freq of each bit and sliding window it