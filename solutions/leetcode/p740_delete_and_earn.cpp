class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> pts;
        for(const int& n : nums){
            pts[n] += n;
        }

        int ans = 0;
        for(const auto& it : pts){
            if(pts.find(it.first-1) != pts.end()){
                continue;
            }
            ans += getMaxPts(it.first, pts);
        }
        return ans;
    }
private:
    int getMaxPts(int start, unordered_map<int,int>& pts){
        int p2=0, p1=0;
        while(pts.find(start) != pts.end()){
            int t = p1;
            p1 = p2+pts[start];
            p2 = max(p2, t);
            start++;
        }
        return max(p1, p2);
    }
};

// we can either include or not include curr number based on prev decisions -> DP
// can count pts from each num, then get the maxPts of each continuous sequence
// O(n) time, O(n) space