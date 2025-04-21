class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long mx = *max_element(milestones.begin(), milestones.end());
        long long sm = accumulate(milestones.begin(), milestones.end(), 0LL);
        if(sm-mx<mx) return 2*(sm-mx)+1;
        return sm;
    }
};

// bounded by max element
// if sum of rest > max, then ans = 2*max+1
// else we can do all tasks, then ans = sum(milestones)