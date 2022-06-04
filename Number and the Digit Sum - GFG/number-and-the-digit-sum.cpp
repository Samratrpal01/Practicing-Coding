// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

typedef long long ll;
class Solution
{
    public:
        ll sum(int n)
        {
            int result=0;
            while(n)
            {
                result+=n%10;
                n/=10;
            }
            
            
            return result;
        }
    
        long long int numberCount(long long int N, long long int K)
        {
            ll count=0;
            for(int i=1;i<=N;i++)
            {
                ll ans=sum(i);
                    if(i-ans>=K)
                        count++;
            }
            
            return count;
        }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n, k;
		cin >> n >> k;
		Solution ob;
		cout <<ob.numberCount(n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends