class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> pos;
        vector<int> ans;

        for(int i=0; i<asteroids.size(); ++i){
            if(asteroids[i]>0){
                pos.push_back(asteroids[i]);
            }
            else{
                while(pos.size()>0 && -1*asteroids[i]>pos.back()){
                    pos.pop_back();
                }
                if(pos.size()>0 && -1*asteroids[i]==pos.back()) pos.pop_back();
                else if(pos.empty()) ans.push_back(asteroids[i]);
            }
        }

        while(pos.size()>0){
            ans.push_back(pos.front());
            pos.pop_front();
        }
        return ans;
    }
};

// stack with all positive asteroids
// whenever we encounter a negative asteroid:
//      pop stack until stack empty or negative asteroid destroyed
// if we encounter negative and stack empty, push to ans
// O(n) time, O(n) space

// CLARIFY PROBLEM
// INIT THOUGHTS
// POTENTIAL SOLUTIONS
// STEPS OF SOLUTION
// PROVE CHOSEN SOLUTION CORRECTNESS W TEST CASE
// TIME AND SPACE COMPLEXITY OF SOLUTION
// PROVE THAT IT IS BEST COMPLEXITY ELSE
// THINK OF ANY POSSIBLE OPTIMIZATIONS FOR TIME
// THINK OF ANY POSSIBLE OPTIMIZATIONS FOR SPACE AFTER TIME SOLUTION CHOSEN
// IMPLEMENT SOLUTION
// OPTIMIZE / ORGANIZE CODE
    