class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return arr;
        
        vector<int> rank(arr.begin(), arr.end());
        sort(rank.begin(), rank.end());
        
        int r=1;
        unordered_map<int,int> r_mp;
        r_mp[rank[0]] = r;
        for(int i=1; i<rank.size(); ++i){
            if(rank[i]==rank[i-1]) continue;
            r++;
            r_mp[rank[i]] = r;
        }
        
        for(int i=0; i<arr.size(); ++i){
            arr[i] = r_mp[arr[i]];
        }
        return arr;
    }
};

// need order of array elements, therefore requires sorting, therefore O(nlogn)
// can sort, map rank to num, then iterate over arr and change each element to its rank
