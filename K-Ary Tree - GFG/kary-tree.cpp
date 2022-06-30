// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

typedef long long ll;
int M= 1e9+7;
class Solution {
  public:
    long long karyTree(ll k, ll m) {
        // answer is (k^m)%1e9+7
        ll ans =1;
        while(m>0){
            if(m&1)
                ans= (ans * k)%M;
            k= (k*k)%M;
            m/=2;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends