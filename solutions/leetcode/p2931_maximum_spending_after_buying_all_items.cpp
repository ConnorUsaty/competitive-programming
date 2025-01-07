class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int n = values.size();
        int m = values[0].size();
        vector<int> a(n*m);

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                a[i*m + j] = values[i][j];
            }
        }
        sort(a.begin(), a.end());

        long long ans=0, d=1;
        for(const int& n : a){
            ans += n * d++;
        }
        return ans;
    }
};

// we can use the fact that each row is sorted in decreasing order
// this means that the current minimum is always available for selection and thus we can just select in order