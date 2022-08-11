class Solution {
public:
    int countOdds(int low, int high) {
       int count=0;
        if(low&1 || high&1)
            count++;
       
        count+=(high-low)/2;
        return count;
    }
};