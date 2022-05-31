class Solution {
public:
    int recursion(int index,int buy,vector <int> &prices,vector <vector <int>>&dp)
    {
        if(index>=prices.size())
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        if(buy)
            return dp[index][buy]=max(-prices[index]+recursion(index+1,0,prices,dp),recursion(index+1,buy,prices,dp));
        else
            return dp[index][buy]=max(prices[index]+recursion(index+2,1,prices,dp),recursion(index+1,buy,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        vector <vector <int>> dp(prices.size(),vector <int>(2,-1));
        return recursion(0,1,prices,dp);
    }
};