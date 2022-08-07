class Solution {
public:
    int recursion(int index,string &s,int k,char &lastPicked,vector <vector <int>> &dp)
    {
        if(index == s.length())
            return 0;
        int pick=0,notpick=0;
        if(dp[index][lastPicked-'`'] != -1)
            return dp[index][lastPicked-'`'];
        if(lastPicked == '`')
            pick=1+recursion(index+1,s,k,s[index],dp);
        else if(abs(s[index]-lastPicked) <=k)
            pick=1+recursion(index+1,s,k,s[index],dp); 
        notpick=recursion(index+1,s,k,lastPicked,dp);
        return dp[index][lastPicked-'`']=max(pick,notpick);
    }
    int longestIdealString(string s, int k) {
        vector <vector <int>> dp(s.length()+1,vector <int>(27,-1));
        char last='`';
        return recursion(0,s,k,last,dp);
    }
};