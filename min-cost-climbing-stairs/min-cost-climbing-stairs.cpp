class Solution {
public:
    int recursion(vector <int> &cost,vector <int> &dp ,int index)
    {
        if(index==cost.size()-1)
            return cost[index];
        if(index>=cost.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        return dp[index]=min(cost[index]+recursion(cost,dp,index+1),cost[index]+recursion(cost,dp,index+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector <int> dp(cost.size()-1,-1),dp1(cost.size()-1,-1);
        return min(recursion(cost,dp,0),recursion(cost,dp1,1));
    }
};