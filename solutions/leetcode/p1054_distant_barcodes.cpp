class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> cnt;
        int mx_cnt=-1, mx_b=-1;
        for(const int& b : barcodes){
            if(++cnt[b] > mx_cnt){
                mx_cnt = cnt[b];
                mx_b = b;
            }
        }

        vector<int> ans((int)barcodes.size());
        int i=0;
        while(cnt[mx_b]--){
            ans[i] = mx_b;
            i+=2;
        }

        for(auto& it : cnt){
            while(it.second-->0){
                if(i>(int)barcodes.size()-1) i=1;
                ans[i] = it.first;
                i += 2;
            }
        }

        return ans;
    }
};

// the important thing to note is that we are guarenteed a solution
// if we were not guarenteed we would have to check that mx_cnt <= floor((n+1)/2)
// since we need at least one slot in between any type of element it is clearly bounded by the majority element

// we have to specifically deal with the majority first, ensuring it gets all the slots it needs to have a space in between each occurence
// then we can simply iterate over the remaining elements placing them in the next available slot
// since they are not the majority element it is guarenteed there will be enough space for them