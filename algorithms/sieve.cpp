/* Generate all primes from 2 to n in O(n*log(log(n))) */

#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n = 200;
    vector<int> prime(n+1, 1);
    prime[0] = prime[1] = 0;
    for(int i=2; i<=n; ++i){
        if(prime[i] && i*i<=n){
            for(int j=i*i; j<=n; j+=i){
                prime[j]=0;
            }
        }
    }

    for(int i=100; i<n; ++i){
        if(prime[i]){
            cout << i << ' ';
        }
    }
    cout << "\n";

    return 0;
}