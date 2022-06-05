// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    unordered_map<char,int>um;
    int n=s.size();
    for(int i=0; i<n; i++)
        um[s[i]]++;
    set<int>us;
    for(auto x:um)
    us.insert(x.second);
    if(us.size()<3)
    {  
       if(*us.begin()==1)
       return true;
       if(*--us.end()-*us.begin()<2)
       return true;
    }
    return false;
	}
	
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}


  // } Driver Code Ends