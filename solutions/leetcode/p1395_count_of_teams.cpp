class Solution {
private:
    void BITadd(vector<int>& BIT, int k, int x){
        while(k < BIT.size()){
            BIT[k] += x;
            k += k&-k;
        }
    }

    int BITsum(vector<int>& BIT, int k){
        int cnt = 0;
        while(k>=1){
            cnt += BIT[k];
            k -= k&-k;
        }
        return cnt;
    }

public:
    int numTeams(vector<int>& rating) {
        int m = *max_element(rating.begin(), rating.end());
        vector<int> leftBIT(m+1, 0); // BIT for elements indexed left of curr element
        vector<int> rightBIT(m+1, 0); // BIT for elements indexed right of curr element

        for(const int& r : rating){
            BITadd(rightBIT, r, 1);
        }

        int ans = 0;
        for(const int& r : rating){
            BITadd(rightBIT, r, -1); // take out current element before query

            int sl = BITsum(leftBIT, r-1);
            int bl = BITsum(leftBIT, m) - BITsum(leftBIT, r);
            int sr = BITsum(rightBIT, r-1);
            int br = BITsum(rightBIT, m) - BITsum(rightBIT, r);

            ans += (sl * br);
            ans += (bl * sr);

            BITadd(leftBIT, r, 1); // add to left for query next idx
        }
        return ans;
    }
};

// can utilize BIT (Binary Indexed Tree) or Fenwick Tree to get range queries in O(logn) and update ranges in O(logn)
// prefix sums can range query in O(1), BUT to update range takes O(n)
// problem can be simplified to count of > * < on either side, which is a range query
// since we need to update our ranges as we iterate we choose BIT instead of prefix sum
// BIT is normally 1-indexed (way easier implementation), BITsum(k) returns sum([0] to [k]) insclusive, therefore sum(a to b) inclusive = BITsum(b) - BITsum(a-1);
