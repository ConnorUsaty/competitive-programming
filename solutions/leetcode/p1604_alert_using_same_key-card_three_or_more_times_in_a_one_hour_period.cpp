class Solution {
private:
    int parse_int(string& s, int i) {
        int res = 0;
        while(i<s.size() && isdigit(s[i])) {
            res *= 10;
            res += (s[i] - '0');
            i++;
        }
        return res;
    }
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        const int n = (int)keyName.size();
        vector<int> rank(n);
        iota(rank.begin(), rank.end(), 0);
        sort(rank.begin(), rank.end(), [&keyTime](int i, int j) {
            return keyTime[i] < keyTime[j];
        });

        vector<string> ans;
        unordered_map<string,queue<int>> people;
        for(auto& i : rank) {
            string name = keyName[i];
            string time_str = keyTime[i];
            int time = parse_int(time_str, 0)*60 + parse_int(time_str,3);
            auto it = people.find(name);
            if (it == people.end()) {
                people[name].push(time);
            } else {
                queue<int>& q = it->second;
                if(!q.empty() && q.front() == -1) continue;
                while(!q.empty() && q.front() < time-60) {
                    q.pop();
                }
                q.push(time);
                if(q.size() >= 3) {
                    ans.push_back(name);
                    while(!q.empty()) { q.pop(); }
                    q.push(-1);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};