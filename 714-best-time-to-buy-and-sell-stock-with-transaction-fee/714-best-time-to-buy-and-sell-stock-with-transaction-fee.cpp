class Solution {
public:
    int recursion(int index,int buy,vector <int> &prices,int fee,vector <vector <int>> &dp)
    {
        if(index==prices.size())
            return 0;
        if(dp[index][buy] != -1)
            return dp[index][buy];
        if(buy)
        {
            return dp[index][buy]=max(-prices[index]+recursion(index+1,0,prices,fee,dp),0+recursion(index+1,buy,prices,fee,dp));
        }
        else
        {
            return dp[index][buy]=max(prices[index]-fee+recursion(index+1,1,prices,fee,dp),0+recursion(index+1,buy,prices,fee,dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector <vector <int>> dp(prices.size()+1,vector <int>(2,-1));
        return recursion(0,1,prices,fee,dp);
    }
};