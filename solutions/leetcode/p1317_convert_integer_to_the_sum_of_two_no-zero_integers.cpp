class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int p=1, m=0, num=n;

        while(n>1){
            int d=(n%10);
            if(d==1){
                m+=2*p;
                n-=2;
            }else{
                m+=p;
                n--;
            }
            p*=10;
            n/=10;
        }

        return vector<int>{num-m, m};
    }

};

// O(logn)

// return two numbers that add up to n that have no '0' digits
// % 10^i at each iter
// split digit into two parts where neither are a zero