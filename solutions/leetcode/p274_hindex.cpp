class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        
        // Count frequencies, capping at n
        for (int c : citations) {
            count[min(c, n)]++;
        }
        
        // Count papers from high to low
        int papers = 0;
        for (int i = n; i >= 0; i--) {
            papers += count[i];
            if (papers >= i) return i;
        }
        
        return 0;
    }
};

// map<int,int> in cpp is ORDERED map -> implemented with BST, sorted ascending by default, therefore n insertions take O(nlogn) time, but elements are ordered by key
// unordered_map<int,int> in cpp is UNORDERED hash table implementation -> implemented using a hash function in cpp, therefore n insertions take O(n) time but no order to elements

// can keep freq / cnt array to only n indexes as impossible for hindex higher than n