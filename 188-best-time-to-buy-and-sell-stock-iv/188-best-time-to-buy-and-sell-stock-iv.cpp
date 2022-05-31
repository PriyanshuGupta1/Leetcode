class Solution {
public:
    int recursion(int index,int TransactionNo,vector <int> &prices,vector <vector <int>> &dp,int k)
    {
        if(index==prices.size() || TransactionNo==k)
            return 0;
        if(dp[index][TransactionNo] != -1)
            return dp[index][TransactionNo];
        if(TransactionNo %2 == 0)
            return dp[index][TransactionNo]=max(-prices[index]+recursion(index+1,TransactionNo+1,prices,dp,k),0+recursion(index+1,TransactionNo,prices,dp,k));
        else
            return dp[index][TransactionNo]=max(prices[index]+recursion(index+1,TransactionNo+1,prices,dp,k),0+recursion(index+1,TransactionNo,prices,dp,k));
    }
    int maxProfit(int k,vector<int>& prices) {
        vector <vector <int>> dp(prices.size(),vector <int>(2*k,-1));
        // vector <vector <int >> dp()
        return recursion(0,0,prices,dp,2*k);
    }
};