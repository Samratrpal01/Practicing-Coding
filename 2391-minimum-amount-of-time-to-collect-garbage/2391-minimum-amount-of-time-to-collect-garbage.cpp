class Solution {
public:
    int garbageCollection(vector<string>& G, vector<int>& travel) {
        int res=0;
        int M=0,Go=0,P=0;
        int maxM=0,maxP=0,maxG=0;
        for(int i=0;i<G.size();i++)
        {
            for(auto temp:G[i])
            {
                if(temp=='G')
                {    Go++;
                 maxG=i;
                }
                if(temp=='M')
                {   M++;
                 maxM=i;
                }
                if(temp=='P')
                {   P++;
                 maxP=i;
                }
            }
        }
        cout<<P<<" "<<Go<<" "<<M<<endl;
        cout<<maxP<<" "<<maxG<<" "<<maxM;
        for(int i=1;i<travel.size();i++)
        {
            travel[i]+=travel[i-1];
        }
        
        if(maxG!=0)
            res+=travel[maxG-1]+Go;
        else
            res+=Go;
        if(maxP!=0)
            res+=travel[maxP-1]+P;
        else
            res+=P;

        if(maxM!=0)
            res+=travel[maxM-1]+M;
        else
            res+=M;
        return res;
            
        
    }
};