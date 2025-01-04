class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = (int) cardPoints.size();

        if(k == cardPoints.size()) return accumulate(cardPoints.begin(), cardPoints.end(), 0);

        vector<int> p_sum(n+1, 0);
        vector<int> s_sum(n+1, 0);
        for(int i=0; i<n; ++i){
            p_sum[i+1] = cardPoints[i] + p_sum[i];
        }
        for(int i=n-1; i>=0; --i){
            s_sum[i] = cardPoints[i] + s_sum[i+1];
        }

        int ans = -1;
        int w_size = n-k;
        for(int i=0; i<=n-w_size; ++i){
            int curr_sum = p_sum[i] + s_sum[i+w_size];
            ans = max(ans, curr_sum);
        }

        return ans;
    }
};

// p_sum[i] contains prefix sum, sum of all elements BEFORE and NOT including [i], i.e. sum(a[:i])
// therefore we can access p_sum[0] safely and get 0, as there are no elements before
// if we want a range sum inclusively from index 2 to 5 we calculate it like so: sum = p_sum[5+1] - p_sum[2]
// note that we need to create p_sum to be n+1 space as we will need to access [n] to get the sum of the entire array
// we have to go one index further than the right index to include it
// we can keep the left index the same to include it and minus everything from before that index

// accumlate(start, end, start sum and type) can be used to calculate a range sum using std functions