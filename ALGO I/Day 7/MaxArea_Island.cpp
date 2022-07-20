 class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid)
    {
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c] == 0)
        {
            return 0;
        }
        grid[r][c] = 0 ;
        int top     = dfs(r-1,c,grid);
        int bottom  = dfs(r+1,c,grid);
        int left    = dfs(r,c-1,grid);
        int right   = dfs(r,c+1,grid);
        
        return 1 + top + bottom + left + right ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int rsz = grid.size(); int csz = grid[0].size();
        int res = 0 ;
        for(int i=0; i<rsz; i++)
        {
            for(int j=0; j<csz; j++)
            {
                if(grid[i][j]){res = max(res, dfs(i,j,grid)) ;}
            }
        }
        return res;
    }
};
