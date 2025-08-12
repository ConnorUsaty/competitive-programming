class Solution {
private:
    int post_order(int u, vector<vector<int>>& children, string& s, int& ans){
        int longest = 0, second_longest = 0;
        for(auto& v : children[u]){
            // need to traverse regardless to update ans
            int len = post_order(v, children, s, ans);
            if(s[u] == s[v]) continue;

            if(len > longest){
                second_longest = longest;
                longest = len;
            }
            else if(len > second_longest) {
                second_longest = len;
            }
        }
        ans = max(ans, longest + second_longest + 1);
        return longest + 1;
    }
    
public:
    int longestPath(vector<int>& parent, string s) {
        const int n = (int)parent.size();

        vector<vector<int>> children(n);
        for(int i=1; i<n; ++i){
            children[parent[i]].push_back(i);
        }

        int ans = 0;
        // 0 = root
        post_order(0, children, s, ans);
        return ans;
    }

};

// n-ary tree
// need to maintain the 2 longest paths from its n children
// need to consider if path ends in same letter as curr -> cannot connect
// then update ans by connecting these 2
// then can pass upwards only the longest path