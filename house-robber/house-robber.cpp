class Solution {
public:
    int recursion(vector <int> &nums,vector <int> &dp,int index)
    {
        if(index==nums.size()-1)
            return nums[index];
        if(index>=nums.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        return dp[index]=max(nums[index]+recursion(nums,dp,index+2),recursion(nums,dp,index+1));
    }
    int rob(vector<int>& nums) 
    {
        vector <int> dp(nums.size()-1,-1);
        return recursion(nums,dp,0);
    }
    
};