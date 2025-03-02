class Solution {
private:
    int dist(const vector<int>& a){
        return a[0]*a[0] + a[1]*a[1];
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> d;
        for(const auto& p : points){
            d.push_back({dist(p), {p[0], p[1]}});
        }
        
        nth_element(d.begin(), d.begin()+k, d.end());
        
        vector<vector<int>> ans;
        for(int i=0; i<k; ++i){
            ans.push_back(d[i].second);
        }
        return ans;
            
        // klogn + nlogn
        // n + klogn + n
    }
};

// nth_element(start, nth, end, comp); element [0] to [n] will be sorted