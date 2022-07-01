class Solution {
public:
    int recursion(int day,vector <int> &days,vector <int> &costs,vector <int> &dp)
    {
        if(day>days[days.size()-1])
            return 0;
        //buy a 1 day pass
        int i;
        for(i=0;i<days.size();i++)
            if(days[i]>=day)
                break;  
        if(dp[days[i]+1] != -1)
            return dp[days[i]+1];
        int day1=costs[0]+recursion(days[i]+1,days,costs,dp);
        //buy a 7 day pass
        int day7=costs[1]+recursion(days[i]+7,days,costs,dp);
        //buy a 30 day pass
        int day30=costs[2]+recursion(days[i]+30,days,costs,dp);
        return dp[days[i]+1]=min(day1,min(day7,day30));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector <int> dp(367,-1);
        return recursion(0,days,costs,dp);
    }
};