class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int, vector<int>, greater<int>> mxs;

        for(int i=0; i<grid.size(); ++i){
            priority_queue<int> pq(grid[i].begin(), grid[i].end());

            for(int j=0; j<min((int)grid[i].size(), limits[i]); ++j){
                if(mxs.size()<k){
                    mxs.push(pq.top());
                }
                else if(!mxs.empty() && mxs.top()<pq.top()){
                    mxs.pop();
                    mxs.push(pq.top());
                }
                pq.pop();
            }
        }
        long long ans = 0;
        while(mxs.size()>0){
            ans += mxs.top();
            mxs.pop();
        }
        return ans;
    }
};

// use min heap to store k biggest elements to save space / time
// can use nth_element(start_it, nth_it, end_it, comp) to get first min/max elements
// cannot iterate over pq without popping
// always ensure non-empty pq before popping
