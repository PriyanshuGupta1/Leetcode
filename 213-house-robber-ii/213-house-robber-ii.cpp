class Solution {
public:
    int recursive(vector <int> &nums,int index,vector <int> &dp,int size)
    {
        if(index==size-1)
            return nums[index];
        if(index>=size)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int p=nums[index]+recursive(nums,index+2,dp,size);
        int np=recursive(nums,index+1,dp,size);
        return dp[index]=max(np,p);
    }
    int rob(vector<int> &nums) {
        vector <int> dp1(nums.size()-1,-1),dp2(nums.size()-1,-1);
        int n=nums.size();
        if(n==1)
            return nums[0];
        return max(recursive(nums,1,dp1,n),recursive(nums,0,dp2,n-1));
    }
};