class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if(nums.size()<=1)
            return nums;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i];
            nums[i]=sum;
        }
        return nums;
    }
};