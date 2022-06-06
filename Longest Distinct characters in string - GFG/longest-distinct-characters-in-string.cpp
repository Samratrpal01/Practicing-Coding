// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    int j=0,res=0;
    vector<int>resu(256,-1);
    for(int i=0;i<S.length();i++)
    {
        j=max(j,resu[S[i]]+1);
        int maxEnd=i-j+1;
        res=max(res,maxEnd);
        resu[S[i]]=i;
        
    }
    return res;
}