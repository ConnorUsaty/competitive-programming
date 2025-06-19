class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> cnt;
        int avail = 0;
        for(int i=0; i<(int)arr.size(); ++i){
            int r = (arr[i] % k + k) % k;
            if(cnt[k-r] > 0){
                cnt[k-r]--;
                avail--;
            }
            else if(r==0 && cnt[0]>0){
                cnt[r]--;
                avail--;
            }
            else{
                cnt[r]++;
                avail++;
            }
        }
        return (avail == 0);
    }
};