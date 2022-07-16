class Solution {
public:
    long mod=10e8+7;
    int recursion(int i,int j,int m,int n,int maxMove,vector <vector <vector <int>>> &dp)
    {
        if(maxMove<0)
            return 0;
        if(i<0 || j<0 || i==m || j==n)
            return 1;
        if(dp[i][j][maxMove] != -1)
            return dp[i][j][maxMove];
        return dp[i][j][maxMove]=(recursion(i+1,j,m,n,maxMove-1,dp)%mod+recursion(i,j+1,m,n,maxMove-1,dp)%mod+recursion(i-1,j,m,n,maxMove-1,dp)%mod+recursion(i,j-1,m,n,maxMove-1,dp)%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector <vector <vector<int>>> dp(m+1,vector <vector<int>> (n+1,vector <int>(maxMove+1,-1)));
        return dp[startRow][startColumn][maxMove]=recursion(startRow,startColumn,m,n,maxMove,dp);
    }
};