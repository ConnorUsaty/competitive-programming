class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if((int)nums.size()==0) return ans;

        int prev = nums[0], l=nums[0];

        for(int i=1;i<(int)nums.size();++i){
            if(nums[i]==prev+1){
                prev=nums[i];
            }
            else if (l==prev){
                ans.push_back(to_string(l));
                l = nums[i];
                prev = nums[i];
            }
            else{
                string curr = to_string(l) + "->" + to_string(prev);
                ans.push_back(curr);
                l = nums[i];
                prev = nums[i];
            }
        }
        
        if(l==prev){
            ans.push_back(to_string(l));
        } else{
            string curr = to_string(l) + "->" + to_string(prev);
            ans.push_back(curr);
        }

        return ans;
    }
};

// to_string(n) converts n to string format in c++