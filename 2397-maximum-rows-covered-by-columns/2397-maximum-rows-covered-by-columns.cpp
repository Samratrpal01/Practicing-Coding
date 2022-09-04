class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
       int Max=0;
        for(int mask=0;mask<(1<<mat[0].size());mask++)
       {    
            if(__builtin_popcount(mask)!=cols)
                continue;
            int cnt=0;
           for(int i=0;i<mat.size();i++)
           {    bool check=true;
               for(int j=0;j<mat[0].size();j++)
               {
                   if((mask>>j&1)==0 and mat[i][j]==1)
                   {
                      check=false;
                       break;
                   }
               }
            if(check)
                cnt++;}
            Max=max(Max,cnt);
           
       }
        
        
        return Max;
    }
};
 
       
          
           
            
               
                   