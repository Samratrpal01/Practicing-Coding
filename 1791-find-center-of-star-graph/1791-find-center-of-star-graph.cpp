class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>v[100004];
        for(auto x:edges)
        {
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }
        int Max=0;
        int Max_idx=0;
        for(int i=0;i<100004;i++)
        {
            if(Max<v[i].size())
            {
                Max=v[i].size();
                Max_idx=i;
            }
            
        }
        return Max_idx;
    }
};