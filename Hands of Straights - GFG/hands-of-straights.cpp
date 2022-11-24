//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n,int k, vector<int> &a) {
         if(k==1)return true;

                if(n%k!=0)  return false;

        sort(a.begin(),a.end());

        map<int,vector<int>>mp;

        int p;int t;

        for(int i=0;i<n;i++)

        {

            p=a[i];

            if(mp[p-1].empty()){mp[p].push_back(k-1);

            }

            else

            {

                t=mp[p-1].back();

                mp[p-1].pop_back();

                if(t>1) mp[p].push_back(t-1);

            }

        }

        int i;

        for(auto x:mp)

        {

          if(x.second.size()!=0)    return false;

        }

        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends