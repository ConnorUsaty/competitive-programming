class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == 0) return num;

        deque<int> q;
        std::string ans;
        int l = 0;
        for(int i=0; i<num.size(); ++i) {
            while (!q.empty() && i - q.front() > k) {
                q.pop_front();
            }
            while (!q.empty() && num[q.back()] > num[i]) {
                q.pop_back();
            }
            q.push_back(i);

            if(i-l == k) {
                if(!ans.empty() || num[q.front()] != '0') {
                    ans.push_back(num[q.front()]);
                }
                k -= q.front() - l;
                l = q.front() + 1;
                q.pop_front();
            }
        }
        return (ans == "" ? "0" : ans);
    }
};

// sliding window of size k+1
// choose min each time to make sure most sig dig is small as possible
// if l = min_idx + 1, k -= min_idx - l

// if min == 0 && ans.empty() -> dont add to ans