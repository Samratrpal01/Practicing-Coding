class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
         int n=stones.size();
    int range=0;
    for(auto i:stones)
        range+=i;
    int sum=range/2;
    bool dp[n+1][sum+1];
    
    for(int i=0; i<sum+1; i++)
        dp[0][i]=false;
    
    for(int i=0; i<n+1; i++)
        dp[i][0]=true;
    
   for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(stones[i-1]<=j)
                dp[i][j]=dp[i-1][j] || dp[i-1][j-stones[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    
    vector<bool> v;
    for(int i=0; i<sum+1; i++){
        v.push_back(dp[n][i]);
    }
    int mini=INT_MAX;  
    for(int i=0; i<v.size(); i++){
        if(v[i])
            mini=min(mini,range-2*i);
    }
    return mini;

    }
};