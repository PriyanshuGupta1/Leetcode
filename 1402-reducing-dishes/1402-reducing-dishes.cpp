class Solution {
public:
    int recursion(int index,int time,vector <int> &satisfaction,vector <vector <int>> &dp)
    {
        if(index == satisfaction.size() )
            return 0;
        if(dp[index][time] != -1)
            return dp[index][time];
        int pick = time*satisfaction[index]+recursion(index+1 ,time+1,satisfaction,dp);
        int notpick=recursion(index+1,time,satisfaction,dp);
        return dp[index][time]=max(pick,notpick);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        // sort the array 
        // apply dp on it
        sort(satisfaction.begin(),satisfaction.end());
        vector <vector <int>> dp(satisfaction.size()+1,vector <int> (satisfaction.size()+1,-1));
        return recursion(0,1,satisfaction,dp);
    }
};