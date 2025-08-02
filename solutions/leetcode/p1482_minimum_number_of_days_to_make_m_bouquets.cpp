class Solution {
private:
    bool check(int mid, vector<int>& b, int m, int k){
        int curr = 0;
        for(int i=0; i<b.size(); ++i){
            if(b[i]<=mid) curr++;
            else curr = 0;

            if(curr == k){
                if(--m == 0) return true;
                curr = 0;
            }
        }
        return false;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*k > (long long)bloomDay.size()) return -1;

        long long l=0, r=*max_element(bloomDay.begin(), bloomDay.end()) + 1;
        while(l<=r){
            long long mid = l+(r-l)/2;
            if(check(mid, bloomDay, m, k)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return r+1;
    }
};