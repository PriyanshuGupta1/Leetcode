class Solution {
public:
    int calc(int n,vector <int> &dp)
    {
        if(n<=1)
            return n;
        if(n==2)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=calc(n-1,dp)+calc(n-2,dp)+calc(n-3,dp);
    }
    int tribonacci(int n) {      
        vector <int> dp(n+1,-1);
        return dp[n]=calc(n,dp);
    }
};