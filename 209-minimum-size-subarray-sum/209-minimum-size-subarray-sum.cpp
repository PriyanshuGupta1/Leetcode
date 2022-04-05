class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int max_len=INT_MAX,left=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            while(sum>=target)
            {
                max_len=min(max_len,i+1-left);
                sum-=nums[left];
                left++;
            }
        }
        if(max_len==INT_MAX)
            return 0;
        else
            return max_len;
    }
};