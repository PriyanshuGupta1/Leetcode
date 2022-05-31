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
        vector <vector <int>> dp(prices.size()+2,vector <int>(2,0));
        for(int index=prices.size()-1;index>=0;index--)
        {
            for(int buy=0;buy<2;buy++)
            {
                if(buy)
                    dp[index][buy]=max(-prices[index]+dp[index+1][0],dp[index+1][buy]);
                else
                    dp[index][buy]=max(prices[index]+dp[index+2][1],dp[index+1][buy]);
            }
        }
        
        return dp[0][1];
    }
};