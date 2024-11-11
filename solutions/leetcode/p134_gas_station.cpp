class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_gas=0, total_gas=0, ans=0;

        for(int i=0;i<cost.size();++i){
            if (curr_gas<0){
                curr_gas = 0;
                ans = i;
            }
            curr_gas += gas[i]-cost[i];
            total_gas += gas[i]-cost[i];
        }

        if (total_gas>=0) return ans;
        else return -1;
    }
};

// Utitlize Kadane's algorithm to find a valid starting point
// Utilize gas sum to check if possible