class TopVotedCandidate {
private:
    vector<int> ans_;
    vector<int> times_;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) : times_(times) {
        vector<int> votes((int)persons.size(), 0);
        int mx_votes=0;
        int mx_idx=-1;
        for(int i=0; i<(int)persons.size(); ++i){
            votes[persons[i]]++;
            if(votes[persons[i]]>=mx_votes){
                mx_votes = votes[persons[i]];
                mx_idx = persons[i];
            }
            ans_.push_back(mx_idx);
        }
    }
    
    int q(int t) {
        int l=0, r=(int)times_.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(times_[m]<=t){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return ans_[l-1];
    }
};

// O(n) setup time
// O(n) setup space

// O(logn) query time
// O(1) query space

// we can precompute who will be the top voted candidate at each [i] in times
// then for each query we binary search the times and find the idx i that corresponds to the most recent vote at time t
// we can binary search times ONLY BECAUSE times is constrained to be STRICTLY INCREASING
// we then simply return who was winning at the time of the most recent vote from our precomputed ans_ array

/**
    * Your TopVotedCandidate object will be instantiated and called as such:
    * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
    * int param_1 = obj->q(t);
    */