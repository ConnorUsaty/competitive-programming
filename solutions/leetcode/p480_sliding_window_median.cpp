using ll = long long;

class Solution {
private:
    template<typename T>
    void clean_heap(T& pq, unordered_map<ll,ll>& removal_cnt) {
        while(!pq.empty() && removal_cnt[pq.top()] > 0) {
            removal_cnt[pq.top()]--;
            pq.pop();
        }
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        unordered_map<ll,ll> removal_cnt;
        priority_queue<ll> bottom_heap;
        priority_queue<ll, vector<ll>, greater<ll>> top_heap;
        ll lz_left = 0, lz_right = 0; // num of elements acc in left / right
        vector<double> ans;
        
        for(int i=0; i<nums.size(); ++i) {
            // insert
            if (bottom_heap.empty() || bottom_heap.top()>=nums[i]) {
                bottom_heap.push(nums[i]);
                lz_left++;
            } else {
                top_heap.push(nums[i]);
                lz_right++;
            }

            clean_heap(bottom_heap, removal_cnt);
            clean_heap(top_heap, removal_cnt);

            // balance
            while(lz_left > lz_right+1) {
                top_heap.push(bottom_heap.top());
                bottom_heap.pop();
                lz_left--;
                lz_right++;
                clean_heap(bottom_heap, removal_cnt);
            }
            while(lz_left < lz_right) {
                bottom_heap.push(top_heap.top());
                top_heap.pop();
                lz_left++;
                lz_right--;
                clean_heap(top_heap, removal_cnt);
            }

            if(i >= k-1) {
                if (k&1) {
                    ans.emplace_back(static_cast<double>(bottom_heap.top()));
                } else {
                    ans.emplace_back(static_cast<double>(bottom_heap.top() + top_heap.top()) / 2.0);
                }
                int to_remove = nums[i-k+1];
                removal_cnt[to_remove]++;
                if(to_remove <= bottom_heap.top()) lz_left--;
                else lz_right--;
            }
        }
        return ans;
    }
};

// use 2 pq to split into top and bottom half
// use unordered_map to lazily delete
// need to keep track of lz_left and lz_right cnts to properly push / pop

// we want to always be able pull from max (bottom) heap
// so median should be there, therefore bottom.size() should be = or +1 of top