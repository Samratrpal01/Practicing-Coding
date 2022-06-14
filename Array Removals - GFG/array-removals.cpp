// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& a, int k){
      sort(a.begin(),a.end());
        int j = a.size()-1,mx = INT_MIN;
        while(j >= 0){
            int low = lower_bound(a.begin(),a.end(),a[j] - k) - a.begin();
            mx = max(mx, j - low + 1);
            j--;
        }
        return a.size() - mx;
        
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends