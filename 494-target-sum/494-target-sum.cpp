class Solution {
public:
    int recursion(int index,vector <int> &nums,int sum,int target)
    {
        if(target==sum && nums.size()==index)
            return 1;
        if(index==nums.size())
            return 0;
        // cout<<sum<<" "<<index<<endl;
        return recursion(index+1,nums,sum-nums[index],target)+recursion(index+1,nums,sum+nums[index],target);
    
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return recursion(0,nums,0,target);
    }
};