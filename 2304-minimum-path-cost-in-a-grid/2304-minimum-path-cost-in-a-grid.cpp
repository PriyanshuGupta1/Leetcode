class Solution {
public:
    int recursion(vector<vector<int>>& grid, vector<vector<int>>& moveCost,int i,int j,vector <vector <int>> &dp)
    {
        if(i==grid.size()-1)
            return grid[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mini=1e9;
        for(int p=0;p<grid[i].size();p++)
        {
            mini=min(mini,recursion(grid,moveCost,i+1,p,dp)+moveCost[grid[i][j]][p]+grid[i][j]);
        }
        return dp[i][j]=mini;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        if(grid.size()==0)
            return 0;
        int mini=1e9;
        vector <vector <int>> dp(grid.size(),vector <int>(grid[0].size(),-1));
        for(int i=0;i<grid[0].size();i++)
            mini=min(mini,recursion(grid,moveCost,0,i,dp));
        return mini;
    }
};