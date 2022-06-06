// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
typedef long long ll;
class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        ll count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int temp=A[i]%K;
            if(temp==0 and mp.find(0)!=mp.end())
                  count+=mp[0];
            else if(mp.find(K-temp)!=mp.end())
                count+=mp[K-temp];
            mp[temp]++;
        }
        
        return count;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends