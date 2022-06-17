class Solution {
public:
    int recursion(int i,int j,vector <vector <int>> &matrix,vector <vector <int>> &dp)
    {
        if(j<0 || j>=matrix[0].size())
            return INT_MAX;
        if(i==matrix.size()-1)
            return matrix[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j]=matrix[i][j]+min(recursion(i+1,j,matrix,dp),min(recursion(i+1,j-1,matrix,dp),recursion(i+1,j+1,matrix,dp)));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector <vector <int>> dp(matrix.size(),vector <int> (matrix.size(),0));
        for(int i=0;i<matrix.size();i++)
            dp[0][i]=matrix[0][i];
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                int top=INT_MAX,left_top=INT_MAX,right_top=INT_MAX;
                if(j>0)
                    left_top=dp[i-1][j-1];
                if(j<matrix[0].size()-1)
                    right_top=dp[i-1][j+1];
                top=dp[i-1][j];
                dp[i][j]=matrix[i][j]+min(top,min(right_top,left_top));
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<matrix.size();i++)
            mini=min(mini,dp[matrix.size()-1][i]);
        return mini;
    }
};