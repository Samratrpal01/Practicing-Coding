// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int getCandidate(int n, int k);


int main() {

    int t;
    cin >> t;
    while(t--){
    	int n, k;
    	cin >> n >> k;
    	cout << getCandidate(n, k) << endl;
    }
return 0;
}
// } Driver Code Ends


int getCandidate(int n, int k){
    int r=1;
    while(r<n)
    {
        if(r*k>n)
            break;
        r=r*k;
    }
    
    return r;
}