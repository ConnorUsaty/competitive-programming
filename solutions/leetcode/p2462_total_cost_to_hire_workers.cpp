using pii = pair<int,int>;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=static_cast<int>(costs.size());

        auto cmp = [](const pii& a, const pii& b){
            return ((a.first > b.first) || (a.first==b.first && a.second > b.second));
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

        candidates = min(candidates, n/2 + (n%2));
        for(int i=0; i<candidates; ++i){
            pq.push({costs[i], i});
            if(n-1-i == i) break;
            pq.push({costs[n-1-i], n-1-i});
        }
        
        long long ans=0;
        int l=candidates, r=n-1-candidates;
        for(int i=0; i<k; ++i){
            auto [c, j] = pq.top();
            pq.pop();
            ans += 1LL*c;

            if(r<l) continue;

            if(j>r){
                pq.push({costs[r], r});
                r--;
            }
            else if(j<l){
                pq.push({costs[l], l});
                l++;
            }
        }
        return ans;
    }
};

// minheap with {val, idx}

// pop value and ans += val
// if r<l do nothing
// if idx > r then we know to add in {costs[r], r} to heap and do r--
// if idx < l then we know to add in {cost[l], l} to heap and do l++
// continue for k iterations