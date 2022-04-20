Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
  
Codes Are:-
  int dp[20];
  int numTrees(int n)
{
  if(n<=1)
    return 1;
  if(dp[n]>0)
    return dp[n];
  
  for(int i=1;i<=n;i++)
  {
    dp[i]+=numTree(i-1)*numTree(n-i);
  }
  return dp[n];
}
