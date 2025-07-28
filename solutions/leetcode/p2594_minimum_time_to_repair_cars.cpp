class Solution {
private:
    bool check(long long m, int cars, vector<int>& ranks){
        for(int i=0; i<ranks.size(); ++i){
            cars -= (long long)sqrt(m/(1LL*ranks[i]));
            if(cars <= 0) return true;
        }
        return false;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=1, r=*min_element(ranks.begin(), ranks.end()) * (1LL*cars*cars)+1;

        while(l<=r){
            long long m = l+(r-l)/2;
            if(!check(m, cars, ranks)){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return r+1;
    }
};

// lower rank = faster repair

// bin search