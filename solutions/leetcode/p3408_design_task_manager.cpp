using pii = pair<int,int>;

auto cmp = [](const pii& a, const pii& b){
    return (a.second<b.second || (a.second==b.second && a.first<b.first));
};

class TaskManager {
private:
    priority_queue<pii, vector<pii>, decltype(cmp)> pq;
    unordered_map<int, pii> mp;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto const & t : tasks){
            mp[t[1]] = {t[2], t[0]};
            pq.push({t[1], t[2]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {priority, userId};
        pq.push({taskId, priority});
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId].first = newPriority;
        pq.push({taskId, newPriority});
    }
    
    void rmv(int taskId) {
        mp[taskId].first = -1;
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [task, p1] = pq.top();
            pq.pop();
            auto [p2, u] = mp[task];
            if(p1 == p2) {
                rmv(task);
                return u;
            }
        }
        return -1;
    }
};

// map taskId to priority and userId
// store tasks in heap with highest priority, then taskID
// lazily edit / remove by updating the priority in the taskID map
// remember to mark as removed after execTop()

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */