/*
Practice implementation of finding number of squares made with n points
*/

#include <vector>
#include <unordered_map>
#include <iostream>

int d(const std::vector<int>& p1, const std::vector<int>& p2){
    return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
}

int solve(std::vector<std::vector<int>> pts) {
    // parition pt pairs by distance -> key = dist, val = list of point pairs with dist = key
    std::unordered_map<int, std::vector<std::pair<std::vector<int>,std::vector<int>>>> dist_mp;
    for(int i=0; i<pts.size(); ++i){
        for(int j=i+1;j<pts.size();++j){
            dist_mp[d(pts[i], pts[j])].push_back({pts[i], pts[j]});
        }
    }

    int squares = 0;

    for(auto it : dist_mp){
        if(it.first==0 || it.second.size()<4) continue;

        for(int i=0; i<it.second.size(); ++i){
            for(int j=i+1; j<it.second.size(); ++j){
                std::vector<int> p1 = it.second[i].first;
                std::vector<int> p2 = it.second[i].second;
                std::vector<int> p3 = it.second[j].first;
                std::vector<int> p4 = it.second[j].second;

                if(d(p1,p3)==0 || d(p1,p4)==0) continue;

                if(d(p1,p3)==d(p2,p4) && d(p1,p4)==d(p2,p3) && (d(p1,p2)==d(p1,p3) || d(p1,p2)==d(p1,p4))){
                    squares++;
                }
            }
        }
    }

    return squares / 2;
}

int main() {
    std::vector<std::vector<int>> pts = {{-1,3},{0,0},{-1,3},{2,4},{3,1},{200,0},{202,0},{201,1},{201,-1},{202,0},{0,400},{0,404},{2,402},{-2,402},{3,403},{3,403},{5,5},{1000,53},{913,0},{3,4}};
    std::cout << "Total squares: " << solve(pts);
    // Expected output with current test case = 5

    // Solution is O(n^2) time, O(n^2) space
    // Remember to check that dist between all pts > 0 to avoid overcounting duplicates
    // remember to typedef ll and pii to save a lot of implementation time
    // for test cases test all scenarios, start simple, axis aligned, then duplicate point, then vertical diag, then horizontal, then unaligned, then random points

    return 0;
}

// PAY ATTENTION TO INPUT TYPE, MAP AND DISTANCE FUNCTION MUST USE THAT TYPE