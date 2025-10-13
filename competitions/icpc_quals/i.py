# int n;
# cin >> n;
# vector<ll> a(n);
# for(int i=0; i<n; ++i) {
#     cin >> a[i];
# }
# vector<ll> s(n);
# for(int i=0; i<n; ++i) {
#     cin >> s[i];
# }
# sort(s.begin(), s.end());

# long double ans = 0.0;
# long double res = 0.0;
# for(int i=0; i<n; ++i) {
#     res += s[i];
#     ans = max(ans, (res+a[i]) / (1.0*i));
# }
# cout << ans << "\n";

n = int(input())
a = list(map(int,input().split()))
v = list(map(int,input().split()))
v.sort(reverse=True)

ans = 0.0
res = 0.0
for i in range(1, n+1):
    res += v[i-1]
    ans = max(ans, (res+a[i-1]) / i) 

print(ans)
