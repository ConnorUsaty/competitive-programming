class DetectSquares {
private:
    map<pair<int,int>,int> point_cnt;

public:
    DetectSquares() {}
    
    void add(vector<int> point) {
        point_cnt[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x1=point[0], y1=point[1];
        int ans=0;
        for(const auto& it : point_cnt){
            int x2=it.first.first, y2=it.first.second;
            if(x1==x2 || y1==y2) continue;
            if(abs(x1-x2)==abs(y1-y2)){
                ans += point_cnt[{x1,y2}] * point_cnt[{x2,y1}] * it.second;
            }
        }
        return ans;
    }
};

// pair<int,int> as key is MUCH faster than vector<int> key
// do not have to do point_cnt.find(x1,y2) != point_cnt.end()
// we can just do point_cnt[x1,y2] and it will return / init that key to 0
// have to check abs() vals for case where x increases but y decreases or vice versa i.e. diag point is up to left or down to rights

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */