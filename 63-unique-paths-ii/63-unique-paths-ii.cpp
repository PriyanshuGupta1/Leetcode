class Solution {
public:
    int recursion(int i,int j,vector<vector<int>> grid,int m,int n,vector<vector<int>> &dp)
    {
        if(i>=m || j>=n)
            return 0;
        if(grid[i][j]==1)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return recursion(i+1,j,grid,m,n,dp)+recursion(i,j+1,grid,m,n,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector <vector <int>> dp(m,vector <int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {    
                if(i==0 && j==0 && grid[i][j]!=1)
                    dp[0][0]=1;
                else
                {
                    if(grid[i][j]==1)
                        dp[i][j]=0;
                    else
                    {
                        if(i>0)
                            dp[i][j]+=dp[i-1][j];
                        if(j>0)
                            dp[i][j]+=dp[i][j-1];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};