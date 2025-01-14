/*
    Given a parameter r2, where the equation x^2+y^2=r2 holds.
    Return a list of points that 
        (1) x and y are both integers
        (2) fits the circle equation
*/

#include <vector>
#include <iostream>

std::vector<int> getPoints(int r2){
    std::vector<std::pair<int,int>> ans;
    int x=1;
    while(x*x<=r2){
        int l=0;
        int r=x;
        while(l<=r){
            int m = l+(r-l)/2;
            if(x*x + m*m == r2){
                std::vector<std::pair<int,int>> cords;
                if(m==0) cords = {{-x,m},{x,m},{m,-x},{m,x}};
                else cords = {{x,m},{-x,m},{x,-m},{-x,-m},{-m,x},{m,-x}};
                ans.insert(ans.end(), cords.begin(), cords.end());
                break;
            } 
            else if(x*x + m*m < r2){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        x++;
    }

    for(auto c : ans){
        std::cout << c.first << ' ' << c.second;
        std::cout << "\n";
    }
}

int main(){
    getPoints(9);
    return 0;
}
