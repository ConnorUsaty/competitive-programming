class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans((int)boxes.size(), 0);
        int ops=0, cnt=0;
        for(int i=0; i<(int)boxes.size(); ++i){
            ans[i] += ops;
            cnt += (boxes[i] == '1') ? 1 : 0;
            ops += cnt;
        }
        ops=0; cnt=0;
        for(int i=(int)boxes.size()-1; i>=0; --i){
            ans[i] += ops;
            cnt += (boxes[i] == '1') ? 1 : 0;
            ops += cnt;
        }
        return ans;
    }
};

// same intuition as product of array except self
// O(n) time, O(n) space (including output vector)
