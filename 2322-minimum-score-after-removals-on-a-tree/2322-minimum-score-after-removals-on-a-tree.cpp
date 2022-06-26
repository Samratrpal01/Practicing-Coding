class Solution {
public:
   int dp[1005];//for each node i such that  0< i <n dp[i] stores the value of the xor for the subtree strats from i 
    vector<int>adj[1005];// this is adjacency list 
    int ans=1e9;//here is the answer will be stored
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        for(auto it:edges){//build the adjacency list
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<nums.size();++i)dp[i]=nums[i];//initially the value of the dp[i] is the value of the root (which is i)
        dfs(0,-1);//build dp[i] to store the value of the xor for each subtree
        int n=nums.size();
        for(int i=1;i<n;++i){
            dfs2(0,-1,i,0);
        }
        return ans;
    }
    int dfs2(int node,int par,int n,bool ok){
        ok|=node==n;//check wheather the path from 1 to the current node pathed through the predifined node
        int ret=node==n;//to store if the subtree starts from node has the predefined node as a child or not
        for(int nxt:adj[node]){
            if(par==nxt)continue;
            ret|=dfs2(nxt,node,n,ok);
        }
        if(!ret&&node!=0&&node!=n){//if the current node is not the first node and it's node the predifind node and the subtree starts from node doesn't have the predifined node as a child then we can cut the tree here
            int x1=dp[0]^dp[n]^dp[node];
            int x2=dp[n];
            int x3=dp[node];
            if(ok)
                x1^=dp[node],x2^=dp[node];//if we pathed through the predefined node ,then we xored the value of this subtree twice so we need to add it
            ans=min(ans,max({x1,x2,x3})-min({x1,x2,x3}));
        }
        return ret;
    }
    int dfs(int node,int par){
        for(int nxt:adj[node]){
            if(par==nxt)continue;
            dp[node]^=dfs(nxt,node);
        }
        return dp[node];
    }
};