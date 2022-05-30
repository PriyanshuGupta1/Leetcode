class Solution {
public:
    int recursion(int r1,int c1,int c2,vector <vector <int>>&grid,vector <vector<vector <int>>>&dp)
    {
        int r2=r1+c1-c2;
        int n=grid.size();
        if(r2>=n || r1>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return INT_MIN;
        int ans=0;
        if(dp[r1][c1][c2]!=-1)
            return dp[r1][c1][c2];
        if(r2==n-1 && c2==n-1)
            return grid[r1][c1];
        if(grid[r1][c1]==1)
            ans+=grid[r1][c1];
        if(r1!=r2 && c1!=c2)
            ans+=grid[r2][c2];
        ans+=max({recursion(r1+1,c1,c2,grid,dp),recursion(r1+1,c1,c2+1,grid,dp),recursion(r1,c1+1,c2,grid,dp),recursion(r1,c1+1,c2+1,grid,dp)});
        return dp[r1][c1][c2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector <vector <vector <int>>> dp(n,vector <vector <int >>(n,vector <int>(n,-1)));
        int ans= recursion(0,0,0,grid,dp);
        if(ans<0)
            return 0;
        else
            return ans;
    }
};