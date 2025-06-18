using pii = pair<int,int>;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<pii> stk;

        for(int i=0; i<(int)arr.size(); ++i){
            pii curr = {arr[i], arr[i]};
            while(!stk.empty() && curr.second<stk.top().first){
                curr.first = max(curr.first, stk.top().first);
                curr.second = min(curr.second, stk.top().second);
                stk.pop();
            }
            stk.push(curr);
        }
        return stk.size();
    }
};

// bound by having a number lower