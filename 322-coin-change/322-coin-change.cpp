class Solution {
public:
    int recursion(int index,int amount,vector <int> &coins,vector <vector <int>> &dp)
    {
        if(index==0)
        {
            if(amount%coins[index]==0)
                return amount/coins[index];
            else
                return 1e9;
        }
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int pick=1e9;
        if(coins[index]<=amount)
            pick=recursion(index,amount-coins[index],coins,dp)+1;
        int notpick=recursion(index-1,amount,coins,dp);
        
        return dp[index][amount]=min(pick,notpick);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        vector <vector <int>> dp(n+1,vector <int>(amount+1,-1));
        int t=recursion(n-1,amount,coins,dp);
        if(t>=1e9)
            return -1;
        else
            return t;
    }
};