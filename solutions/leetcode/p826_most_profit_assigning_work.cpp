class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int jobs = (int)difficulty.size();
        vector<int> rank(jobs);
        iota(rank.begin(), rank.end(), 0);
        sort(rank.begin(), rank.end(), [&profit](int i, int j) {
            return profit[i]>profit[j];
        });
        sort(worker.begin(), worker.end(), std::greater<>());

        int job_idx = 0, ans = 0;
        for(const int & w : worker) {
            while(job_idx < jobs && w < difficulty[rank[job_idx]]) {
                ++job_idx;
            }
            if(job_idx >= jobs) break;
            ans += profit[rank[job_idx]];
        }
        return ans;
    }
};

// we always want workers to take most profitable job possible
// so sort jobs in order of profit and assign in order of strength
// anytime a previous worker couldn't do a job the current can't either

// O(nlogn) time, O(n) space