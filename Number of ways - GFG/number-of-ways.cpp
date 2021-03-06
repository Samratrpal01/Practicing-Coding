// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int arrangeTiles(int N){
        long long int dp[N+1];
        dp[0]=1;
        for(int i=1;i<=N;i++)
        {
            if(i==1 or i==2 or i==3)
                dp[i]=1;
                else
                    dp[i]=dp[i-4]+dp[i-1];
        }
        return dp[N];
    }
    
    
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends