// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Function to return maximum XOR subset in set[]
#define for1(i,a,b) for(int i=a;i<b;i++)
#define for2(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define pb push_back
class Solution
{
    public:
    
int bit(int n){
    int ans=0;
    while(n>0){
        n>>=1;ans++;
    }
    return ans;
}
vi adj[33];
int maxSubarrayXOR(int A[], int n)
{
        for1(i,0,33) adj[i].clear();
        int x,m,max1=0;
        vi ans;
        for1(i,0,n){
            m=bit(A[i]);max1=max(m,max1);
            adj[m].pb(A[i]);
        }
        for2(i,max1,1){
            if(adj[i].size()>0){
                ans.pb(adj[i][0]);
                for(int j=1;j<adj[i].size();j++){
                    int k=(adj[i][j]^adj[i][0]);
                    adj[bit(k)].pb(k);
                }
            }
        }
        int ans1=0;
        for(int x1:ans){
            if(ans1<(ans1^x1)) ans1^=x1;
        }
        return ans1;
}
};

// { Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubarrayXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}  // } Driver Code Ends