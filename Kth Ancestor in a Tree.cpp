// complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.


// Example 1:



// Input:
//      K = 2
//      Node = 4
// Output: 1
// Explanation:
// Since, K is 2 and node is 4, so we
// first need to locate the node and
// look k times its ancestors.
// Here in this Case node 4 has 1 as his
// 2nd Ancestor aka the Root of the tree.
 

// Example 2:

// Input:
// k=1 
// node=3
//       1
//     /   \
//     2     3

// Output:
// 1
// Explanation:
// K=1 and node=3 ,Kth ancestor of node 3 is 1.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

 

// Constraints:
// 1<=N<=104
// 1<= K <= 100

// Codes ARe:-
void solve(Node* root,int k,int node,vector<int> ans,int &val){
   if(root==NULL) return;
   
   ans.push_back(root->data);
   if(root->data==node && ans.size()>=k){
       for(int i=ans.size()-1;i>=0;i--){
           if(k==0) val=ans[i];
           k--;
       }
   }
   
   solve(root->left,k,node,ans,val);
   solve(root->right,k,node,ans,val);
}

int kthAncestor(Node *root, int k, int node)
{
   // Code here
   vector<int>ans;
   int val=0;
   solve(root,k,node,ans,val);
   
if(val==0) return -1;
else return val;
}
