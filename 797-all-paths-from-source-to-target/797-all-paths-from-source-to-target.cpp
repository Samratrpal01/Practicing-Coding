class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<vector<int>>graph,vector<int>path,int start,int end)
    {path.push_back(start);
        if(start==end)
        {res.push_back(path);
            return;
        }
        for(auto i:graph[start])
            dfs(graph,path,i,end);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        int n=graph.size();
        dfs(graph,path,0,n-1);
        return res;
    }
};