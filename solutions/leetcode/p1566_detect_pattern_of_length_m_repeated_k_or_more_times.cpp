class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        const int n = (int)arr.size();

        int p=0, curr=0;
        for(int i=m; i<n; ++i){
            if(arr[i]==arr[i-m]){
                if(++p==m){
                    p=0;
                    if(++curr==k-1){
                        return true;
                    }
                }
            }
            else{
                p=0;
                curr=0;
            }
        }
        return false;
    }
};

// check if arr[i] == arr[i-m]
// if yes p++;
//      if p == m, curr++
//          if curr == k, return true
// else
//      p=0, curr=0
