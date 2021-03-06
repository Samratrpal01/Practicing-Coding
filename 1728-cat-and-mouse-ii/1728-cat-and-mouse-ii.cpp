class Solution {
public:
    int n,c;
    pair<int,int>C,m,f;
    int dp[74][8][8][8][8];
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1},};
    
    bool isvalid(pair<int,int>a,vector<string>& grid){
        return (a.first>=0 && a.second>=0 && a.first<n && a.second<c && grid[a.first][a.second]!='#');
    }
    
    int find(int cJ,int mJ,int t,pair<int,int>C,pair<int,int>m,vector<string>& grid){
        if(t>73 || C==f || C==m)
            return 0;
        if(m==f)
            return 1;
        if(dp[t][C.first][C.second][m.first][m.second]!=-1)
            return dp[t][C.first][C.second][m.first][m.second];
        int who = t%2;
        if(!who){
            for(int i=0;i<4;i++){
                for(int j =0;j<=mJ;j++){
                    int x = m.first+dir[i][0]*j;
                    int y = m.second+dir[i][1]*j;
                    if(isvalid({x,y},grid)){
                        int nxt = find(cJ,mJ,t+1,C,{x,y},grid);
                        if(nxt==1) return dp[t][C.first][C.second][m.first][m.second]=1;
                    }
                    else
                        break;
                }
            }
            return dp[t][C.first][C.second][m.first][m.second]=0;
        }
        else{
            for(int i=0;i<4;i++){
                for(int j =0;j<=cJ;j++){
                    int x = C.first+dir[i][0]*j;
                    int y = C.second+dir[i][1]*j;
                    if(isvalid({x,y},grid)){
                        //cout<<x<<" "<<y<<endl;
                        int nxt = find(cJ,mJ,t+1,{x,y},m,grid);
                        if(nxt==0) return dp[t][C.first][C.second][m.first][m.second]=0;
                    }
                    else
                        break;
                }
            }
           
            return dp[t][C.first][C.second][m.first][m.second]=1;
        }
            
    }
    
public:
    bool canMouseWin(vector<string>& grid, int cJ, int mJ) {
        n =grid.size();
        c = grid[0].length();
        memset(dp,-1,sizeof(dp));
        for(int i =0;i<n;i++){
            for(int j =0;j<c;j++){
                if(grid[i][j]=='F')
                    f={i,j};
                else if(grid[i][j]=='C')
                    C={i,j};
                else if(grid[i][j]=='M')
                    m={i,j};
            }
        }
        
        return find(cJ,mJ,0,C,m,grid);
    }
};