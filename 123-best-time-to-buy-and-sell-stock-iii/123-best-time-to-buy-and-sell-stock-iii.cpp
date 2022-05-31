class Solution {
public:
    int recursion(int index,int buy,int cap,vector <int> &prices,vector <vector <vector <int>>> &dp)
    {
        if(index==prices.size() || cap==0)
            return 0;
        if(dp[index][buy][cap] != -1)
            return dp[index][buy][cap];
        if(buy)
            return dp[index][buy][cap]=max(-prices[index]+recursion(index+1,0,cap,prices,dp),0+recursion(index+1,buy,cap,prices,dp));
        else
            return dp[index][buy][cap]=max(prices[index]+recursion(index+1,1,cap-1,prices,dp),0+recursion(index+1,buy,cap,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        vector <vector <vector <int>>> dp(prices.size(),vector <vector <int>>(2,vector <int>(3,-1)));
        return recursion(0,1,2,prices,dp);
    }
};