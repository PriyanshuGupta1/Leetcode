class Solution {
public:
    int recursive(vector <int> &nums,int index,vector <int> &dp){
        if(index==nums.size()-1)
            return nums[index];
        if(index>=nums.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        return dp[index]=max(nums[index]+recursive(nums,index+2,dp),recursive(nums,index+1,dp));
    }
    int rob(vector<int>& nums) 
    {
        vector <int> dp(nums.size()-1,-1);
        return recursive(nums,0,dp);
    }
};