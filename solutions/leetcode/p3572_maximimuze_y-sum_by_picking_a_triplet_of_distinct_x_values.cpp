class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n=static_cast<int>(x.size());
        
        unordered_set<int> used_x;

        vector<int> y_idx(n);
        iota(y_idx.begin(), y_idx.end(), 0);
        sort(y_idx.begin(), y_idx.end(), [&y](const int i, const int j){
            return y[i]>y[j];
        });

        int ans=0;
        for(int i=0; i<n; ++i){
            int y_val = y[y_idx[i]];
            int x_val = x[y_idx[i]];
            if(used_x.find(x_val) == used_x.end()){
                used_x.insert(x_val);
                ans += y_val;
                if(used_x.size()==3) return ans;
            }
        }
        return -1;
    }
};