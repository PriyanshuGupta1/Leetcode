class Solution {
    public:
    int climbStairs(int n) 
    {
        vector <long long > dp(n+1,-1);
        dp[n]=count(n,dp);
        return dp[n];
    }
    int count(long long nStairs,vector<long long> &dp)
    {
        if(nStairs<0)
            return 0;
        if(!nStairs)
            return 1;
        if(dp[nStairs]==-1)
            return dp[nStairs]=(count((nStairs-1),dp)+count((nStairs-2),dp));
        else 
            return dp[nStairs];   
    }
};