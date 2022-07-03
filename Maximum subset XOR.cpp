
// Hard Accuracy: 47.81% Submissions: 16983 Points: 8
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.   
// Given an array arr[] of N positive integers. Find an integer denoting the maximum XOR subset value in the given array arr[].

// Example 1:

// Input : 
// N = 3
// arr[] = {2, 4, 5}
// Output : 7
// Explanation : 
// The subset {2, 5} has maximum 
// subset XOR value.
// Example 2 :

// Input : 
// N= 3
// arr[] = {9, 8, 5}
// Output : 13
// Explanation : 
// The subset {8, 5} has maximum 
// subset XOR value.
// Your Task :
// You don't need to read input or print anything. Your task is to complete the function maxSubarrayXOR() which takes the array and an integer as input and returns the maximum subset XOR value.
 
// Expected Time Complexity : O(N*Log(max(arr[i])))
// Expected Auxiliary Space : O(1)
//  Codes Are:-
#define for1(i,a,b) for(int i=a;i<b;i++)
#define for2(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define pb push_back
class Solution
{
    public:
    
int bit(int n){
    int ans=0;
    while(n>0){
        n>>=1;ans++;
    }
    return ans;
}
vi adj[33];
int maxSubarrayXOR(int A[], int n)
{
        for1(i,0,33) adj[i].clear();
        int x,m,max1=0;
        vi ans;
        for1(i,0,n){
            m=bit(A[i]);max1=max(m,max1);
            adj[m].pb(A[i]);
        }
        for2(i,max1,1){
            if(adj[i].size()>0){
                ans.pb(adj[i][0]);
                for(int j=1;j<adj[i].size();j++){
                    int k=(adj[i][j]^adj[i][0]);
                    adj[bit(k)].pb(k);
                }
            }
        }
        int ans1=0;
        for(int x1:ans){
            if(ans1<(ans1^x1)) ans1^=x1;
        }
        return ans1;
}
};
