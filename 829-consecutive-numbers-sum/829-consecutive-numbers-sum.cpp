class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res=0;
        for(auto n=2;n*(n+1)/2<=N;++n)
        {
            res+=(N-n*(n+1)/2)%n==0?1:0;
        }
        return res+1;
    }
};