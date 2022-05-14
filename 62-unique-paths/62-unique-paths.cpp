class Solution {
public:
    int recursion(int i,int j,int m,int n,vector <vector <int>> dp)
    {
        if(i==m-1 && j==n-1)
            return 1;
        if(i>=m || j>=n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=recursion(i+1,j,m,n,dp)+recursion(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector <vector<int>> dp(m,vector <int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    dp[0][0]=1;
                else
                {
                    if(i>0)
                        dp[i][j]+=dp[i-1][j];
                    if(j>0)
                        dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};