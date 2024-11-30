class Solution {
private:
    int visit(int i, vector<vector<int>>& rooms, vector<int>& visited) {
        if(visited[i]){
            return 0;
        }

        int ans=1;
        visited[i]=1;

        for(const int& r : rooms[i]){
            ans += visit(r, rooms, visited);
        }
        return ans;
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);

        return visit(0, rooms, visited) == rooms.size();
    }
};


// Utilize private helper functions for recursion
// Utilize vectors to track already visited nodes without changing original array
// Always remember to check for a base case in recursive helper func to avoid inf recursion