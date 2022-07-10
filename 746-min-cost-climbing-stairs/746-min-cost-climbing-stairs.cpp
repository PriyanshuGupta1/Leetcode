class Solution {
public:
    int recursion(int index,vector <int> &cost,vector <int> &dp)
    {
        if(index>=cost.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        return dp[index]=cost[index]+min(recursion(index+1,cost,dp),recursion(index+2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector <int> dp(cost.size()+1,-1);
        return min(recursion(0,cost,dp),recursion(1,cost,dp));
    }
};