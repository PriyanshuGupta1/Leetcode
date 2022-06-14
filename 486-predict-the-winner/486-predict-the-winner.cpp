class Solution {
public:
    int recursion(int start,int end,vector <int> & nums,vector <vector <int>> &dp)
    {
        if(start>end)
            return 0;
        if(dp[start][end] != -1)
            return dp[start][end];
        int a=nums[start]-recursion(start+1,end,nums,dp);
        int b=nums[end]-recursion(start,end-1,nums,dp);
        return dp[start][end]=max(a,b);
    }
    bool PredictTheWinner(vector<int>& nums) {
        vector <vector <int>> dp(nums.size(),vector <int>(nums.size(),-1));
        return recursion(0,nums.size()-1,nums,dp)>=0 ? 1:0;
    }
};