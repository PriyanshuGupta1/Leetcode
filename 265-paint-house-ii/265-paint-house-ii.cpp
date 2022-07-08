class Solution {
public:
    int recursion(int index,int prevColour,vector <vector<int>> costs,vector <vector <int>> &dp)
    {
        if(index==costs.size())
            return 0;
        if( dp[index][prevColour] != -1)
            return dp[index][prevColour];
        int cost=10e8;
        for(int j=1;j<=costs[index].size();j++)
        {
            if(j != prevColour)
                cost=min(cost,costs[index][j-1]+recursion(index+1,j,costs,dp));
        }
        return dp[index][prevColour]=cost;
    }
    int minCostII(vector<vector<int>>& costs) {
        vector <vector <int>> dp(costs.size()+1,vector <int> (costs[0].size()+1,0));
        for(int i=0;i<costs[0].size();i++)
            dp[0][i]=costs[0][i];
        for(int i=1;i<costs.size();i++)
        {
            for(int j=0;j<costs[i].size();j++)
            {
                int mini=INT_MAX;
                for(int k=0;k<costs[i].size();k++)
                {
                    if(j != k)
                        mini=min(mini,dp[i-1][k]);
                }
                dp[i][j]=costs[i][j]+mini;
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<costs[0].size();i++)
            mini=min(mini,dp[costs.size()-1][i]);
        return mini;
    }
};