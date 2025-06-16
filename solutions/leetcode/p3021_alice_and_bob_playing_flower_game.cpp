using ll = long long;

class Solution {
public:
    ll flowerGame(int n, int m) {
        ll n_odds = (n+1)/2;
        ll n_evens = n/2;
        ll m_odds = (m+1)/2;
        ll m_evens = m/2;

        return n_odds*m_evens + n_evens*m_odds;
    }
};