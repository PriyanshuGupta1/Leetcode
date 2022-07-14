class Solution {
public:
    int dfs(int i,int j,vector <vector <int>> &grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || grid[i][j]==2)
            return 0;
        grid[i][j]=2;
        return 1+dfs(i+1,j,grid)+dfs(i-1,j,grid)+dfs(i,j-1,grid)+dfs(i,j+1,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    maxArea=max(maxArea,dfs(i,j,grid));
                }
            }
        }
        return maxArea;
    }
};