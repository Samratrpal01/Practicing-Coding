class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
       int dp[n][m];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            dp[0][i]=v[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0)
                {
                    dp[i][j]=v[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j==m-1)
                {
                    dp[i][j]=v[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                }
                else
                    dp[i][j]=v[i][j]+min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]));
                
                    
            }
        }
        int result=INT_MAX;
        for(int i=0;i<m;i++)
        {
            result=min(result,dp[n-1][i]);
        }
        return result;
    }
};