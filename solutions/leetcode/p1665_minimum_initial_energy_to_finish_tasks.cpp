class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks){
        sort(tasks.begin(), tasks.end(),
            [](const vector<int>& a, const vector<int>& b){
                return (a[1]-a[0]) > (b[1]-b[0]);
            }
        );

        int ans = max(tasks[0][0], tasks[0][1]);
        int curr = ans - tasks[0][0];
        for(int i=1; i<(int)tasks.size(); ++i){
            int need = max(0, max(tasks[i][0],tasks[i][1])-curr);
            curr += need;
            ans += need;
            curr -= tasks[i][0];
        }
        return ans;
    }
};

// can sort by difference of (min - acc)
// the higher the difference the more we "save" and thus should complete these first
// then iterate over sorted arr and borrow when necessary

// O(nlogn) time -> fits in n <= 10^5 constraint
// O(1) space