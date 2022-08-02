 class Solution {
public:
    void mark(vector<vector<char>> &grid,int x,int y,int row,int col)
    {
        if(x<0 || x>=row || y<0 || y>=col || grid[x][y]!='1')
        {
            return;
        }
        grid[x][y]='2';
        mark(grid,x+1,y,row,col);
        mark(grid,x,y+1,row,col);
        mark(grid,x-1,y,row,col);
        mark(grid,x,y-1,row,col);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
        {
            return 0;
        }
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    mark(grid,i,j,grid.size(),grid[0].size());
                    count++;
                }
            }
        }
        return count;
    }
};
