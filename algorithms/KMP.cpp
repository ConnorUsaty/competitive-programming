/*
Knuth Morris Pratt (KMP) Algorithm
 - Utilized to find occurence(s) of substring t in string s
 - Utilizes pi table to prevent backtracking in s and solve the problem in O(n+m) as opposed to O(n*m)
 - Time : O(n + m), where n is length of s and m is length of t, n for search/traversal of s, m for creation of pi table
 - Space: O(m), where m is the length of t, for storing pi table
*/

#include <iostream>
#include <vector>
using namespace std;


int KMP(string t, string s){
    // use KMP algorithm to search for t within s, O(m+n)
    int m = (int)t.size();
    int n = (int)s.size();
    vector<int> pi(m, 0);

    // create pi table, O(m)
    for(int i=1; i<m; ++i){
        int j = pi[i-1];
        while(j>0 && t[j]!=t[i]) j = pi[j-1];
        if(j==0 && t[0]!=t[i]) pi[i] = 0;
        else pi[i] = j+1;
    }

    // search s using pi table, O(n)
    int j = 0;
    for(int i=0; i<n; ++i){
        while(j>0 && t[j]!=s[i]) j = pi[j-1];
        if(t[j]==s[i]) j++;
        if(j==m) return i-j+1;
    }

    return -1;
}

int main(){
    string s = "aacbatkot";
    string t = "cbat";

    int i = KMP(t, s);

    if (i != -1) {
        cout << "t occurs in s starting at: [" << i << ']' << "\n";
    } else {
        cout << "t does not occur in s" << "\n";
    }

    return 0;
}
