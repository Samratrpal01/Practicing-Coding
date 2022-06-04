// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

typedef long long ll;
class Solution{
    public:
    long long solve(int arr[], int n){
    sort(arr,arr+n);
      long long ans= ((long long)n*(long long)(n-1))/2;
      
      long long c=1;
      for(long long i=0;i<n-1;i++)
      {
          if(arr[i]==arr[i+1])
          {
              c++;
          }
          else
          {
              ans=ans-(c*(c-1))/2;
              c=1;
          }
      }
       ans=ans-(c*(c-1))/2;
      return ans;
    
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        int arr[n];
        for(int i = 0; i<n; i++)
            cin >> arr[i];
        Solution ob;
        long long ans = ob.solve(arr,n);
        cout << ans << endl;
    }
}
  // } Driver Code Ends