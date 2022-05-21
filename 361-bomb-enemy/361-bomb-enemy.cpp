class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int maxi=0;
        int rowHit=0;
        vector <int> colHit(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0 || grid[i][j-1]=='W')
                {
                    rowHit=0;
                    for(int k=j;k<m;k++)
                    {
                        if(grid[i][k]=='W')
                            break;
                        else if (grid[i][k]=='E')
                            rowHit++;
                    }
                }
                if(i==0 || grid[i-1][j]=='W')
                {
                    colHit[j]=0;
                    for(int k=i;k<n;k++)
                    {
                        if(grid[k][j]=='W')
                            break;
                        else if(grid[k][j]=='E')
                            colHit[j]++; 
                    }
                }
                if(grid[i][j]=='0')
                {
                    maxi=max(maxi,rowHit+colHit[j]);
                }
            }
        }
        return maxi;
    }
};