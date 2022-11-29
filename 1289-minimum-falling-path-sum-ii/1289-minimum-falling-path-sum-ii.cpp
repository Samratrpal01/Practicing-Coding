class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v){
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
                int ans=INT_MAX;
                for(int k=0;k<m;k++)
                {
                    if(j==k)continue;
                    ans=min(ans,v[i][j]+dp[i-1][k]);
                }  
                dp[i][j]=ans;
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