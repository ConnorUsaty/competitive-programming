/*
If given n points how many squares can be formed.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

typedef long long ll;

ll solve(std::vector<std::pair<int,int>>& pts){
    std::unordered_map<int, std::unordered_map<int,int>> cnt;
    for(auto& p : pts){
        cnt[p.first][p.second]++;
    }

    ll ans=0;
    for(auto x=cnt.begin(); x!=cnt.end(); ++x){
        for(auto p1=x->second.begin(); p1!=x->second.end(); ++p1){
            // O(n) -> n pts
            std::cout << x->first << ' ' << p1->first << ' ' << p1->second << "\n";
            for(auto p2=std::next(p1); p2!=x->second.end(); ++p2){
                if(p1 == p2) continue;
                int d = abs(p1->first-p2->first);

                // check for squares with these two points as left
                ans += cnt[x->first+d][p1->first] * cnt[x->first+d][p2->first] * p1->second * p2->second;

                // check for squares with these two points as right
                ans += cnt[x->first-d][p1->first] * cnt[x->first-d][p2->first] * p1->second * p2->second;
            }
            cnt[x->first][p1->first] = 0;
        }
    }
    return ans;
}

int main() {
    std::vector<std::pair<int,int>> pts = {{1,1},{1,2},{2,1},{2,1},{0,0},{1,0},{1,1},{0,1},{100,1},{300,3},{300,3},{400,0},{0,400},{400,400}};
    std::cout << "Total squares: " << solve(pts);

    return 0;
}
