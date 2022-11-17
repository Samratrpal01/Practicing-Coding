//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
  public:
    
    int extractMaximum(string s) 
    { 
        int Max=0;
        int check=0;
        bool found=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0' and s[i]<='9')
            {   found=true;
                check*=10;
                check+=s[i]-'0';
            }
            else
            {
                Max=max(Max,check);
                check=0;
            }
        }
        int n=s.size();
        if(s[n-1]>='0' and s[n-1]<='9')
        Max=max(Max,check);
        
        if(found)
        return Max;
        else
        return -1;
    } 
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.extractMaximum(S)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends