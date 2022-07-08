class Solution {
public:
    int minCost(vector<vector<int>>& cost) {
        // TimeComplexity: O(N*3*2) = O(N)
        // Space Complexity: O(N*3)= O(N)
        vector <int> prev(3,0),curr(3,0);
        for (int j=0;j<3;j++)
            prev[j]=cost[0][j];
        for(int i=1;i<cost.size();i++)
        {
            curr[0]=cost[i][0]+min(prev[1],prev[2]);
            curr[1]=cost[i][1]+min(prev[0],prev[2]);
            curr[2]=cost[i][2]+min(prev[0],prev[1]);
            prev=curr;
        }
        int mini=INT_MAX;
        for (int j=0;j<3;j++)
            mini=min(mini,prev[j]);
        return mini;
    }
};