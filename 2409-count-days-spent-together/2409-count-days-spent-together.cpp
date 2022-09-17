class Solution {
int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


	// Convert date to respective number in year.
    int td(string s) {
        int m = s[1] - '0' + 10*(s[0] - '0');
        int d = s[4] - '0' + 10*(s[3] - '0');
        --m;
        while (m > 0) {
            d += md[m];
            --m;
        }
        return d;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int ans=0;
        int a=td(arriveAlice),b=td(leaveAlice),c=td(arriveBob),d=td(leaveBob);
        for(int i=0;i<=365;i++)
        {
            if(i>=a and i<=b and i>=c and i<=d)
                ans++;
        }
        
        return ans;
        
        
    }
};