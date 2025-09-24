class Solution {
private:
    bool check(vector<int>& machine, vector<int>& stock, vector<int>& cost, long long budget, long long m) {
        for(int j=0; j<machine.size(); ++j) {
            long long need = max(0LL, (machine[j] * m) - stock[j]);
            budget -= 1LL * need * cost[j];
            if(budget < 0) return false;
        }
        return true;
    }

public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        long long ans = 0;
        for(auto& machine : composition) {
            long long l=ans, r=1e9;
            while(l<=r && r>ans) {
                long long m = l+(r-l)/2;
                if(check(machine, stock, cost, budget, m)) {
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
            l = (l==0 ? l : l-1);
            ans = max(ans, l);
        }
        return static_cast<int>(ans);
    }
};

// O(k*nlogn) time
// for each machine bin search and find most alloys possible
// can check in O(n) if a certain m of alloys is possible

// return MAX num alloys company can create

// all alloys must be from SAME machine
// each machine is at composition[i]
// num of mat needed PER ALLOY = composition[i][j]

// cost per alloy = sum(composition[i][j] * cost[j]) for all j