class Solution {
public:
    bool recursion(int index,int lsum,int sum,vector <int> &nums,vector <vector <int>> &dp)
    {
        if(lsum==sum)
            return true;
        if(index>=nums.size() || lsum>sum)
            return false;
        if(dp[index][lsum] != -1)
            return dp[index][lsum];
        return dp[index][lsum]=recursion(index+1,lsum+nums[index],sum,nums,dp) | recursion(index+1,lsum,sum,nums,dp);
    }
    
    bool canPartition(vector<int>& nums) {
        // S1+S2=S S1==S2 S1=S/2;
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        vector <vector <int>> dp(nums.size()+1,vector <int>(sum+1,-1));
        return recursion(0,0,sum/2,nums,dp);
    }
};