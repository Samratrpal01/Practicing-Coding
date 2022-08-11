class Solution {
public:
    int preimageSizeFZF(int K) {
     for (int l = 0, r = INT_MAX; l < r;) {
        int m = l + (r - l) / 2, c = m;
        for (int i = 5; m / i > 0; i *= 5)
            c += m / i; // the m-th is c
        if (c < K)
            l = m + 1;
        else if (c > K)
            r = m;
        else
            return 5;
    }
    return 0;   
    }
};