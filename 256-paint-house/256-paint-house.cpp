class Solution {
public:
    int recursion(int index,int prevColour,vector <vector <int>> &costs,vector <vector <int>> &dp)
    {
        if(index==costs.size())
            return 0;
        if(dp[index][prevColour] != -1)
            return dp[index][prevColour];
        int cost=1e9;
        for(int j=1;j<=costs[0].size();j++)
        {
            if(j != prevColour)
               cost=min(cost,costs[index][j-1]+recursion(index+1,j,costs,dp));
        }
        return dp[index][prevColour]=cost;
    }
    int minCost(vector<vector<int>>& costs) {
        // we will start form 0th index
        // we also need to check what we picked in previous iteration ,that cant be picked in the current iteration
        // 0 1 2 old indexing
        // 0 1 2 3 new indexing ,0 represents no color
        // TimeComplexity: O(N*3*2) = O(N)
        // Space Complexity: O(N*3)= O(N)
        vector <vector <int>> dp(costs.size()+1,vector <int>(costs[0].size()+2,-1));
        return recursion(0,0,costs,dp);
    }
};