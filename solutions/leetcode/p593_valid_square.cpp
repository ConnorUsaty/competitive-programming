class Solution {
public:
    int d(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s({ d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4) });
        return !s.count(0) && s.size() == 2;
    }
};

// THIS SOLUTION ONLY WORKS ON INT ONLY COORDINATES
// IF DOUBLES OR FLOATS ACCEPTED WE HAVE TO CHECK THAT THE COUNTS OF ONE DISTANCE = 4 AND THE COUNT OF THE OTHER = 2

// cannot just check that diagonal lengths match, we also have to check that the 4 side lengths match

// checking for diag then for other points existence doesnt work due to squares that are diagonal and not "upright"


// Optimal O(1), O(1) solution, takes advantage of fact that of the 24 permutations only 3 of them are unique
class Solution {
private:
    int d(const vector<int>& p1, const vector<int>& p2){
        return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    }

    bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
        return (d(p1,p2)>0 && d(p1,p3)>0 && d(p1,p2) == d(p2,p3) && d(p3,p4) == d(p4,p1)
            && d(p1,p3)==d(p2,p4));
    }

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return check(p1,p2,p3,p4) || check(p1,p2,p4,p3) || check(p1,p3,p2,p4);
    }
};
