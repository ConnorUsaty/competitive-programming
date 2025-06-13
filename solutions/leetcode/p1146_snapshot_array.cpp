using pii = pair<int,int>;

class SnapshotArray {
private:
    vector<vector<pii>> arr_;
    size_t snap_id_ = 0;

public:
    SnapshotArray(int length) : arr_(length, vector<pii>{{0, 0}}) {}
    
    void set(int index, int val) {
        if(arr_[index].back().first == snap_id_){
            arr_[index].back().second = val;
        }
        else{
            arr_[index].push_back({snap_id_, val});
        }
    }
    
    int snap() {
        return snap_id_++;
    }
    
    int get(int index, int snap_id) {
        auto& snaps = arr_[index];

        int l=0, r=snaps.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;

            if(snaps[m].first<=snap_id){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        l = (l==0 ? l : l-1);
        return snaps[l].second;
    }
};

// arr_[i] = {snap_id, val} -> O(length * set calls)
// snap_id = 0;

// whenever snap is called return snap_id++; -> O(1)
// whenever set is called if snap_id != arr[-1].first, push_back({snap_id, val}) -> O(1)
// whenever get is called binary search on snap_id to find value -> O(logn)

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */