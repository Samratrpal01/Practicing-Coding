// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(vector<vector<int>>&range, vector<int>queries){
       set<int>s;
       vector<int>ans;
       vector<int>temp;
       
       for(int i=0;i<range.size();i++)
        {
            for(int j=range[i][0];j<=range[i][1];j++)
            {
                s.insert(j);
            }
            
        }
        
        for(int x:s)
        {
            temp.push_back(x);
        }
        
        for(int x:queries)
        {
            if(x>temp.size())
            {
                ans.push_back(-1);
                
            }
            else
                ans.push_back(temp[x-1]);
        }
        
        return ans;
    } 
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(range, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}
  // } Driver Code Ends