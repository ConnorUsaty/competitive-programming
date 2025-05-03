typedef long long ll;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<ll,ll> cnt;
        for(const int& n2 : nums2) cnt[n2*k]++;

        ll ans = 0;
        for(const int& n1 : nums1){
            for(int i=1; i*i<=n1; ++i){
                if(n1%i==0){
                    ans += cnt[i];
                    if(n1/i != i) ans += cnt[n1/i];
                }
            }
        }
        return ans;
    }
};

// Can find all factors of a number n in O(sqrt(n)) time
// O(n*sqrt(l) + m) time, where n = len(nums1), l=max(num1), m=len(nums2)

// for a lot of pairs problems when you are matching an element or index to another element or a previously seen element
// a hashset or hashmap is normally a good solution as it allows for O(1) insertions and checks and therefore an O(n) time