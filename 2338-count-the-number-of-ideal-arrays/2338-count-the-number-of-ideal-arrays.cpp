class Solution {
public:
//     Just find number of sequences having all numbers unique such that a[i] is divisible by a[i-1].
// This count is conntained in tot array. Multiplying this count with the number of ways to expand this array into a N sized array. This ways is stored in dp[i][j] where i refers to number of unique elements and j refers to size of the array.

// Also the maximum length of sequence having a[i] divisible by a[i-1] is just 14(1, 2, 4, 8,...., 2^13).

// For calculating dp[i][j]:-
// Number of ways to fill j sized array with i unique elements is sum of number of ways to fill 1 to j-1 sized array with i-1 unique elements as we can add the remainig space with current element.

// So dp[i][j]=dp[i-1][1]+dp[i-1][2]+dp[i-1][3].....+dp[i-1][j-1]
// And to prevent TLE we are taking the prefix sum of dp values in pr array.
    
    
    int mod=1e9+7,mx,n;
    long long dp[15][10001],pr[15][10001],tot[15];
    void get(int la,int cn){
        tot[cn]++;
        for(int p=2*la;p<=mx;p+=la)get(p,cn+1);
        return;
    }
    int idealArrays(int nn, int mmx) {
        n=nn;mx=mmx;
        memset(dp,0,sizeof(dp));memset(pr,0,sizeof(pr));memset(tot,0,sizeof(tot));
        for(int i=1;i<=10000;i++)
            dp[1][i]=1,pr[1][i]=i;
        
        for(int i=2;i<15;i++){
            for(int j=i;j<=10000;j++){
                dp[i][j]=pr[i-1][j-1];
                pr[i][j]=dp[i][j]+pr[i][j-1];
                dp[i][j]%=mod;
                pr[i][j]%=mod;
            }
        }
        long long ans=mx,x;
        for(int i=1;i<=mx;i++){
            get(i,1);
        }
        for(int i=2;i<15;i++){
            x=tot[i]*dp[i][n];
            x%=mod;
            ans+=x;
            ans%=mod;
        }
        return ans;
    }
};