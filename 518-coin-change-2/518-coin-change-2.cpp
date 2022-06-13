class Solution {
public:
    int recursion(int index,vector <int> &coins,int amount,vector <vector <int>> &dp)
    {
        if(index==coins.size())
            return 0;
        if(amount==0)
            return 1;
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int pick=0;
        if(coins[index]<=amount)
            pick=recursion(index,coins,amount-coins[index],dp);
        int notpick=recursion(index+1,coins,amount,dp);
        return dp[index][amount]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        vector <vector <int>> dp(coins.size(),vector <int> (amount+1,-1));
        return recursion(0,coins,amount,dp);
    }
};