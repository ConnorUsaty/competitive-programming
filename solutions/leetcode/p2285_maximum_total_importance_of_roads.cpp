class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> in(n,0);
        for(auto& r : roads){
            in[r[0]]++;
            in[r[1]]++;
        }
        sort(in.begin(), in.end(), std::greater<>());

        long long ans = 0;
        for(int i=0; i<n; ++i){
            ans += 1LL * in[i] * (n-i);
        }
        return ans;
    }
};

// assign highest values to highest in degree
// this allows the value to be used more in the summation therefore maximizing total importance

// if you use te vector<int> idx, iota(), sort(), trick to get the idxs in order... make sure you need to maintain the original order
// ex: for this soln we just need the sorted in degree values we do not need to keep them in order because we do not care which nodes have which in degree