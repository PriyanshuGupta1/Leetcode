class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            int rowHit=-1;
            for(int j=0;j<m;j++)
            {
                int colHit=0;
                if(grid[i][j]=='0' && rowHit==-1)
                {
                    rowHit=0;
                    for(int k=j-1;k>=0;k--)
                    {
                        if(grid[i][k]=='E')
                            rowHit++;
                        if(grid[i][k]=='W')
                            break;
                    }
                    for(int k=j+1;k<m;k++)
                    {
                        if(grid[i][k]=='E')
                            rowHit++;
                        if(grid[i][k]=='W')
                            break;
                    }
                }
                if(grid[i][j]=='0' && rowHit!=-1)
                {
                    for(int k=i-1;k>=0;k--)
                    {
                        if(grid[k][j]=='E')
                            colHit++;
                        if(grid[k][j]=='W')
                            break;
                    }
                    for(int k=i+1;k<n;k++)
                    {
                        if(grid[k][j]=='E')
                            colHit++;
                        if(grid[k][j]=='W')
                            break;
                    }
                    maxi=max(maxi,rowHit+colHit);
                }
                if(grid[i][j]=='W')
                    rowHit=-1;
            }
            
        }
        return maxi;
    }
};