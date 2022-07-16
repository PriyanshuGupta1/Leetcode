class Solution {
public:
    int recursion(int currLane, int point,vector <int> &obstacles,vector <vector <int>> &dp)
    {
        // we have reached the end
        if(point==obstacles.size()-1)
            return 0;
        // there is a rock ahead change path
        // cout<<currLane << " " << point << endl;
        if( dp[currLane][point] != -1)
            return dp[currLane][point];
        if(obstacles[point+1] == currLane)
        {
            int mini=INT_MAX;
            for(int i=1;i<=3;i++)
            {
                if(currLane != i && obstacles[point] != i)
                    mini=min(mini,recursion(i,point,obstacles,dp));
            }
            return dp[currLane][point]=mini+1;
        }
        else
            return dp[currLane][point]=recursion(currLane,point+1,obstacles,dp);
        
    }
    int minSideJumps(vector<int>& obstacles) {
        int currLane=2,point=0;
        vector <vector <int>> dp(currLane+2,vector <int>(obstacles.size()+1,-1));
        return recursion(currLane,point,obstacles,dp);
    }
};