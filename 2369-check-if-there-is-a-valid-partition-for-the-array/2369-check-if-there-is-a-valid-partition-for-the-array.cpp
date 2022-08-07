class Solution {
public:
    bool recursion(int index,vector <int> &nums,vector <int> &dp)
    {
        if(index == nums.size())
            return true;
        bool curr=false;
        // cout<<index;
        if(dp[index] != -1)
            return dp[index];
        if(index+1 < nums.size())
        {
            if(nums[index] == nums[index+1])
                curr= curr | recursion(index+2,nums,dp);
        }
        if(curr == true)
            return dp[index]=true;
        if(index+2 < nums.size())
        {
            if(nums[index] == nums[index+1] && nums[index+1]== nums[index+2] || nums[index]+1==nums[index+1] && nums[index+1]==nums[index+2]-1)
                curr= curr | recursion(index+3,nums,dp);
            if(curr == true)
                return dp[index]=true;
        }
        return dp[index]=curr;
    }
    bool validPartition(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        vector <int> dp(nums.size()+1 ,-1 );
        return recursion(0,nums,dp);
    }
};