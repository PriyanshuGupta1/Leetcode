class Solution {
public:
    int minCost(vector<vector<int>>& cost) {
        // TimeComplexity: O(N*3*2) = O(N)
        // Space Complexity: O(N*3)= O(N)
        vector <vector <int>> dp(cost.size()+1,vector <int>(cost[0].size()+2,0));
        for (int j=0;j<3;j++)
            dp[0][j]=cost[0][j];
        for(int i=1;i<cost.size();i++)
        {
            dp[i][0]=cost[i][0]+min(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=cost[i][1]+min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=cost[i][2]+min(dp[i-1][0],dp[i-1][1]);
        }
        int mini=INT_MAX;
        for (int j=0;j<3;j++)
            mini=min(mini,dp[cost.size()-1][j]);
        return mini;
    }
};