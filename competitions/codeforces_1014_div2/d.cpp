#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char,int> cnt;
    for(const char& c : s){
        cnt[c]++;
    }

    if(cnt['L']==cnt['I'] && cnt['I']==cnt['T']){
        cout << "0\n";
        return;
    }

    int zeros=0;
    if(cnt['L']==0) zeros++;
    if(cnt['I']==0) zeros++;
    if(cnt['T']==0) zeros++;
    if(zeros==2){
        cout << "-1\n";
        return;
    }

    int mx=0;
    char mx_key;
    int mn=INT_MAX;
    char mn_key;
    for(auto it : cnt){
        if(mx<it.second){
            mx_key = it.first;
            mx = it.second;
        }
        if(mn>it.second){
            mn_key = it.first;
            mn = it.second;
        }
    }
    char md_key;
    if('L'!=mn_key && 'L'!=mx_key){
        md_key = 'L';
    }else if('I'!=mn_key && 'I'!=mx_key){
        md_key = 'I';
    }else{
        md_key = 'T';
    }

    int start;
    for(int i=0; i<n-1; ++i){
        if(s[i]!=mn_key && s[i+1]!=mn_key && s[i]!=s[i+1]){
            start = i+1;
        }
    }

    vector<int> ans;
    int l=start, r=start;
    while(cnt[mn_key]<cnt[mx_key]){
        if(s[start]==mx_key){
            ans.push_back(r);
            r++;
            cnt[mn_key]++;
            if(cnt[mn_key]==cnt[mx_key] && cnt[md_key]==cnt[mx_key]) break;
            ans.push_back(r);
            r++;
            cnt[md_key]++;
        }
        else{
            ans.push_back(l);
            r++;
            cnt[mn_key]++;
            if(cnt[mn_key]==cnt[mx_key]  && cnt[md_key]==cnt[mx_key]) break;
            ans.push_back(l);
            r++;
            cnt[md_key]++;
        }

        if(cnt[mn_key]>cnt[md_key]){
            char t = mn_key;
            mn_key = md_key;
            md_key = t;
        }
        if(cnt[mn_key]>cnt[mx_key]){
            char t = mn_key;
            mn_key = mx_key;
            mx_key = t;
        }
        if(cnt[md_key]>cnt[mx_key]){
            char t = mx_key;
            mx_key = md_key;
            md_key = t;
        }
    }

    cout << (int)ans.size() << "\n";
    for(const int& n : ans) cout << n << "\n";
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
