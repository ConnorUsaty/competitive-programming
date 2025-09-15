class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int n = (int)heights.size();

        priority_queue<int> pq;
        for(int i=0; i<n-1; ++i) {
            int diff = heights[i] - heights[i+1];
            if(diff < 0) {
                pq.push(diff*-1);
                bricks += diff;
            }
            while(bricks < 0 && ladders > 0) {
                bricks += pq.top();
                pq.pop();
                ladders--;
            }
            if(bricks < 0) {
                return i;
            }
        }
        return n-1;
    }
};

// use bricks everytime, store brick usage in heap
// when we run out of bricks, use a ladder on top of heap
// then we get those bricks back and continue

// O(n * log(n))

// we should always use ladders on MAX brick usage to maintain the most bricks possible
// therefore maintain sorted order with heap and use ladders only when necessary to "gain back" the bricks

// use bricks everytime, store brick usage in heap
// when we run out of bricks, use a ladder on top of heap
// then we get those bricks back and continue

// O(n * log(n)) time
// O(n) space