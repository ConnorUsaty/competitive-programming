class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a==e && (c!=a || (b>d && f>d) || (b<d && f<d))) return 1;
        if(b==f && (d!=b || (a>c && e>c) || (a<c && e<c))) return 1;
        if(c-d == e-f && (a-b!=c-d || (a>c && a>e) || (a<c && a<e))) return 1;
        if(c+d == e+f && (a+b!=c+d || (a>c && a>e) || (a<c && a<e))) return 1;
        return 2;
    }
};

// one move if rook x or y = queen x or y OR bishop diag = queen diag
// two moves o.w., rook can always capture in 2