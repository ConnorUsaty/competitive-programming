/*
Binary Exponentiation (fastPow)
 - Calculates (a^b) % m in O(logb)
 - Utilizes binary exponentiation to bring time complexity from O(b) to O(logb)
*/

#include <iostream>
using namespace std;

int fastPow(int a, int b, const int m){
    if (a==0) {
        return b==0;
    }

    int ans=1;
    while(b>0){
        if (b&1) ans = (ans*a) % m; // if b is odd
        b >>= 1LL; // right shift once (divide by 2)
        a = (a*a) % m;
    }
    return ans;
}

int main(){
    const int m = 1e9+7;
    int a=7;
    int b=10;

    int ans = fastPow(a, b, m);

    cout << '(' << a << '^' << b << ')' << " % " << m << " = " << ans << "\n";

    return 0;
}