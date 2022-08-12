class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m=matrix.size(),n=m?matrix[0].size():0,u=0,d=m-1,l=0,r=n-1,p=0;
        vector<int>orders(m*n);
        while(u<=d and l<=r)
        {
            for(int col=l;col<=r;col++)
                orders[p++]=matrix[u][col];
            if(++u>d)
                break;
            for(int row=u;row<=d;row++)
                orders[p++]=matrix[row][r];
            if(--r<l)
                break;
            for(int col=r;col>=l;col--)
                orders[p++]=matrix[d][col];
            if(--d<u)
                break;
            for(int row=d;row>=u;row--)
                orders[p++]=matrix[row][l];
            
            if(l++>r)
                break;
        }
        return orders;
    }
};

