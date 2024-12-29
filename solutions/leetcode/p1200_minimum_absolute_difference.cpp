class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());

        int min_diff = 1e9;
        for(int i=1; i<arr.size(); ++i){
            int diff = arr[i]-arr[i-1];
            if(diff < min_diff){
                ans = {{arr[i-1], arr[i]}};
                min_diff = diff;
            }
            else if(diff == min_diff){
                ans.push_back({arr[i-1], arr[i]});
            }
        }

        return ans;
    }   
};

// sort array -> O(nlogn)
// iterate over array tracking current min and push back if diff = min -> O(n)
// O(nlogn + n) -> O(nlogn)
