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
        vector <vector <int>> dp(matrix.size(),vector <int> (matrix.size(),-1));
        int mini=INT_MAX;
        for(int i=0;i<matrix[0].size();i++)
            mini=min(mini,recursion(0,i,matrix,dp));
        return mini;
    }
};