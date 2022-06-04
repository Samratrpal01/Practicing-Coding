// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int countWords(string s);
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	    {
	        string s;
	        getline(cin,s);
	        cout<<countWords(s)<<endl;
	    }
}// } Driver Code Ends


//User function Template for C++

int countWords(string s)
{
    int count=0, flag=0;      
   for(int i=0; i<s.size(); i++)
    {
        if( (s[i]==' ' || s[i]=='\\' )  )
         {
             if(s[i]=='\\' && (s[i+1]=='t' || s[i+1]=='n') ) i++;
             if(flag) count++; 
             flag=0;
         }
        else
         {
         flag=1;
         }
        
    }
    if (flag) count++;
    
    return count;
}