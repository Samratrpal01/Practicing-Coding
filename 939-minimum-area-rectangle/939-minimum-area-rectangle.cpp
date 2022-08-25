class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans=INT_MAX;
        unordered_map<int,unordered_set<int>>mymap;
        for(auto p:points)
        {
            mymap[p[0]].insert(p[1]);
        }
        
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                
                if(x1!=x2 and y2!=y1)
                {
                    if(mymap[x1].find(y2)!=mymap[x1].end() and mymap[x2].find(y1)!=mymap[x2].end())
                    {
                        ans=min(ans,(abs(x1-x2)*abs(y1-y2)));
                               
                    }
                }
            }
        }
                                return (ans==INT_MAX?0:ans);
    }
                                
};

              