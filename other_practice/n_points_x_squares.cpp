/*
If given n points how many squares can be formed.

O(n^2) time, O(n) space solution
Will work for axis and non axis aligned squares with duplicate points
Important to note that this is built for int only coordiantes
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

typedef long long ll;
typedef std::pair<int,int> pii;

// Custom hash function for std::pair<int, int> 
struct pairHash {
    std::size_t operator()(const pii& p) const {
        return std::hash<int>{}(p.first) ^ (std::hash<int>{}(p.second) << 1);
    }
};

ll solve(std::vector<pii>& pts){
    std::unordered_set<pii, pairHash> pts_set(pts.begin(), pts.end());
    std::unordered_map<pii,int, pairHash> pts_cnt;
    for(const pii& p : pts) {
        pts_cnt[p]++;
    }

    ll squares = 0;
    // for each pt try all other pts as diagonal
    for(auto p1=pts_set.begin(); p1!=pts_set.end(); ++p1){
        for(auto p2=next(p1); p2!=pts_set.end(); ++p2){
            // Three posibilities to be a diagonal
            if(p1->first == p2->first){
                // vertical diagonal -> Non axis aligned square
                double mid_y = (p1->second+p2->second) / 2.0;
                if((int)mid_y != mid_y) continue;
                int x3 = p1->first + abs(p1->second-mid_y);
                int x4 = p1->first - abs(p1->second-mid_y);
                squares += pts_cnt[{p1->first,p1->second}] * pts_cnt[{p2->first,p2->second}] * pts_cnt[{x3,mid_y}] * pts_cnt[{x4,mid_y}];
            }
            else if(p1->second == p2->second){
                // horizontal diagonal -> non axis aligned square
                double mid_x = (p1->first+p2->first) / 2.0;
                if((int)mid_x != mid_x) continue;
                int y3 = p1->second + abs(p1->first-mid_x);
                int y4 = p1->second - abs(p1->first-mid_x);
                squares += pts_cnt[{p1->first,p1->second}] * pts_cnt[{p2->first,p2->second}] * pts_cnt[{mid_x,y3}] * pts_cnt[{mid_x,y4}];
            }
            else if(abs(p1->first-p2->first) == abs(p1->second-p2->second)){
                // axis aligned square
                pii p3 = {p1->first, p2->second};
                pii p4 = {p2->first, p1->second};
                squares += pts_cnt[{p1->first,p1->second}] * pts_cnt[{p2->first,p2->second}] * pts_cnt[p3] * pts_cnt[p4];
            }
        }
    }
    // All squares double counted
    return squares / 2;
}

int main() {
    std::vector<pii> pts = {{1,1},{1,0},{0,1},{0,0},{200,0},{202,0},{201,1},{201,-1},{202,0},{0,400},{0,404},{2,402},{-2,402},{3,403},{5,5},{1000,53},{913,0},{3,4}};
    std::cout << "Total squares: " << solve(pts);
    // Expected output with current test case = 4

    return 0;
}

// same x = possible vertical diag
// same y = possible horizontal diag
// same abs diff on both points = possible axis aligned square
// for horizontal / vertical diagonals get the midpoint, ensure it is an int, then find where the other two pts would have to be to form a square
// return squares / 2 as each pair of points that form a diagonal will count the square leading to double counting
// think through problem carefully drawing out the possible diagonal and where the corresponding other 2 pts would have to be to ensure correct calculations
// for test cases do one test case that checks each of 3 cases alone, then checks case with duplicate, then checks all case together