const int MAX_N = 2001;

class SegmentTree{
public:
    SegmentTree() {
        memset(t,0,sizeof(t));
        memset(lazy,0,sizeof(lazy));
    }

    // query max in range [l,r]
    int query(int v, int tl, int tr, int l, int r){
        if(l>r) return INT_MIN;

        if(lazy[v]!=0){
            execute(v, lazy[v], tl, tr);
            lazy[v] = 0;
        }

        if(tl==l && tr==r){
            return t[v];
        }
        int tm = tl+(tr-tl)/2;
        return merge(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l,tm+1), r));
    }

    // lazily set all nodes in [l,r] to val
    void update(int v, int tl, int tr, int l, int r, int val){
        if(l>r) return;

        if(lazy[v]!=0){
            execute(v, lazy[v], tl, tr);
            lazy[v] = 0;
        }

        if(tl==l && tr==r){
            execute(v, val, tl, tr);
        }
        else{
            int tm = tl+(tr-tl)/2;
            update(v*2, tl, tm, l, min(r,tm), val);
            update(v*2+1, tm+1, tr, max(l,tm+1), r, val);
            t[v] = merge(t[v*2], t[v*2+1]);
        }
    }

    // execute a delayed lazy query
    void execute(int v, int x, int tl, int tr){
        t[v] = merge(t[v], x);
        if(tl != tr){
            lazy[v*2] = merge(lazy[v*2], x);
            lazy[v*2+1] = merge(lazy[v*2+1], x);
        }
    }

    int merge(int a, int b){
        return max(a,b);
    }

private:
    int t[4*MAX_N];
    int lazy[4*MAX_N];
};


class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        unordered_map<int, int> index_mp;
        set<int> sortedCoords;
        for(const auto& pos : positions){
            sortedCoords.insert(pos[0]);
            sortedCoords.insert(pos[0] + pos[1] - 1);
        }
        int compressedIdx = 1;
        for(const int& i : sortedCoords){
            index_mp[i] = compressedIdx;
            compressedIdx++;
        } 
        int n = compressedIdx-1;
        SegmentTree st = SegmentTree();

        int best = 0;
        vector<int> ans;  
        for(const auto& pos : positions){
            int l = index_mp[pos[0]];
            int r = index_mp[pos[0] + pos[1] - 1];
            int mx = st.query(1,1,n,l,r) + pos[1];
            st.update(1,1,n,l,r,mx);
            best = max(best, mx);
            ans.push_back(best);
        }
        return ans;
    }
};

// intervals problem?
// when dropping square query range [l+1,l+len-1]
// place square on top of max, adding + len to [l,l+len] interval
// then get curr max height and push to ans
// segment tree to update and query ranges efficiently?


// segtree notes:
// init size of 4*n, segtrees are 1-indexed, make sure queries account for that
// use lazy propagation for RANGE UPDATES
// need to execute if tl==l && tr==r
// else update both children and t[v] = merge(left, right)
