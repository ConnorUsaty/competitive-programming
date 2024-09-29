#include <bits/stdc++.h> 
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
#include <stack>

typedef long long ll;
typedef long double ld;
// typedef pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int res=s.size();

    // if length even, ans is just changing to max of odd / even
    if(n%2==0)
    {
        // count each character for odd and even indexes
        vector<int>v[2]={vector<int>(26),vector<int>(26)};
        for(int i=0;i<n;i++)
        {
            v[i%2][s[i]-'a']++;
        }

        // for both odd and even parity get the max
        for(int i=0;i<2;i++)
        {
            int mx=0;
            for(int j=0;j<26;j++)
            {
                mx=max(mx,v[i][j]);
            }
            res-=mx;
        }
        cout<<res<<"\n";
    }
    else
    {
        // string is odd length

        // need to get prefix and suffix sums for even and odd. Then when we remove i we can flip the parity for the suffix and caluclate the min answer
        vector<int>pref[2]={vector<int>(26),vector<int>(26)};
        vector<int>suf[2]={vector<int>(26),vector<int>(26)};
        // create suffix counts
        for(int i=n-1;i>=0;i--)
        {
            suf[i%2][s[i]-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            // remove from suffix without adding to prefix yet (simulates ith element being removed)
            suf[i%2][s[i]-'a']--;
            int ans=n;

            // get max of odd and even parity with each element removed
            for(int k=0;k<2;k++)
            {
                int mx=0;
                for(int j=0;j<26;j++)
                {
                    mx=max(mx,suf[1-k][j]+pref[k][j]);
                }
                ans-=mx;
            }
            // take the minimum ans each time
            res=min(res,ans);
            // build prefix sum for next element
            pref[i%2][s[i]-'a']++;
        }
        cout<<res<<"\n";
    }
    return;
}


int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }

    return 0;
}

// 1400 Rating -> prefix sum / count / string problem
// Accepted

// Focus on problem solving and different cases, prove why your solution is correct before implementation
// Remember that prefix / suffix sums are very useful when finding the difference between 2 indexes / over an interval
// When counting letters use an array or vector of length 26 and increment the element - 'a' index
// Remember to think about memory contraints when building prefix sums, it will not work for every problem if the prefix array is way to large
