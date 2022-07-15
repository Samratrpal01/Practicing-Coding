class Solution {
    private:
    int n, m;
    int trav(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j]=='0') return 0;
        grid[i][j] = '0';
        return 1 + trav(i-1, j, grid) + trav(i, j-1, grid) + trav(i+1, j, grid) + trav(i, j+1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
       int ans = 0;
      int count=0;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                if (grid[i][j]=='1'){ans = max(ans, trav(i, j, grid));
                                     count++;}
        return count; 
    }
};
  
