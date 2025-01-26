class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();

        vector<pair<int,int>> cars;
        for(int i=0; i<n; ++i) cars.push_back({position[i], speed[i]});
        sort(cars.rbegin(), cars.rend());

        int ans = 1;
        double curr = ((double)target-cars[0].first)/cars[0].second;

        for(int i=1; i<n; ++i){
            pair<int,int> car = cars[i];
            double arrival_time = ((double)target-car.first)/car.second;
            if(arrival_time>curr){
                curr = arrival_time;
                ans++;
            }
        }

        return ans;
    }
};

// O(nlogn) time -> from sort, O(n) space -> from making cars vector to sort

// have to sort by position first
// can use rbegin and rend to get sorting in opposite order instead of passing in custom comparator
// since we only ever use stk.top() we can actually just use a variable instead of a full stack to save memory
// need to type cast to double so that int division doesnt round towards zero

// d = s*t
// t = d/s
// t = (target-position)/speed
// if arrival time < top, car joins that fleet, do nothing
// if arrival time > top, car is new fleet, add to stack
