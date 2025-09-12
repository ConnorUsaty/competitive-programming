class Solution {
private:
    int get_level(int val) {
        // each level has 2^h+1 -1 nodes
        if(val == 1) return 0;

        int h = 1;
        int nodes = 4;
        while(nodes-1 < val) {
            nodes *= 2;
            h++;
        }
        return h;
    }

    int get_ancestor(int val1, int val2) {
        int cost = 0;
        while(val1 != val2) {
            val1 /= 2;
            val2 /= 2;
            cost++;
        }
        return cost;
    }

public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        ans.reserve(queries.size());

        for(auto& q : queries) {
            int node1 = q[0], node2 = q[1];
            if(node1 > node2) swap(node1, node2); // ensure node1 less

            int h1 = get_level(node1), h2 = get_level(node2);
            int level_diff = h2 - h1;
            // make nodes on same level, level_diff alr accounted for
            for(int i=0; i<level_diff; ++i) {
                node2 /= 2;
            }
            int ancestor_cost = 2 * get_ancestor(node1, node2);
            ans.push_back(level_diff + ancestor_cost + 1);
        }
        
        return ans;
    }
};

// learned:
// if a question gives u specific info use it
// i.e. specifies sorted input or that children = 2*parent
// most tree distance questions boil down to LCA
// the LCA has to be on the optimal path from one node to another

// every query will be 1 + path from q[0] to q[1]
// pre compute every single path -> O(v^2) time, O(v^2) space
// v can be up to 2^30-1, therefore v^2 is too large

// only compute the paths that we need to and memo the downwards paths
// therefore if we dont know path yet go up ?
// that way we only compute a path once

// we know that p = val
// l = 2*val
// r = 2*val+1

// if val lower, to the right or down
// can find level bounds in O(log2(n))
// can then find level distance
// can then find corresponding node on same level as higher node
// ans = level_diff + moves_to_get_to_same_level

// to get to a node with same parent -> 2 edges
// to get to a node with same grandparent -> 4 edges
// to get to a node with same great grandparent -> 6 edges
// goes up +2 per ancestor

// ans = level_diff +  2*ancestor_diff

// to get level_diff -> O(2*log(n))
// to get ancestor -> O(log(n)) -> traverse up until match -> max n = 30
