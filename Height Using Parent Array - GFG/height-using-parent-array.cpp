// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int find(int arr[],int i)
{
    if(arr[i]==-1)
        return 1;
    return 1+find(arr,arr[i]);
}
    int findHeight(int N, int arr[]){
        int h=0;
        for(int i=0;i<N;i++)
        {
            h=max(h,find(arr,i));
        }
        
        return h;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends