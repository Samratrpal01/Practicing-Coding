// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int c=0;
        for(auto i=0;i<n;i++)
        {
            if(arr[i]<=k)
            c++;
        }
        
        if(c==0 or c==1)
            return 0;
        int bad=0,mini=0;
        for(int i=0;i<c;i++)
        {
            if(arr[i]>k)
                bad++;
        }
        
        mini=bad;
        for(int i=c;i<n;i++)
        {
            if(arr[i-c]>k)
            bad--;
            
            if(arr[i]>k)
                bad++;
            mini=min(mini,bad);
        }
        
        return mini;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends