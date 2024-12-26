class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size()>=2){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x!=y){
                pq.push(y-x);
            }
        }

        return (pq.size()>0)?pq.top():0;
    }
};


// pq is a maxHeap by default
// priority_queue <int, vector<int>, greater<int> > pq; creates a minHeap