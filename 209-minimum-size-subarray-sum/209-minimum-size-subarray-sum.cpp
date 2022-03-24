class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int max_len=0,curr_len=0,i=0,sum=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]>=target)
                return 1;
            else if(sum+nums[j]<target)
            {
                sum+=nums[j];
                curr_len++;
            }
            else if(sum+nums[j]>=target)
            {
                sum+=nums[j];
                curr_len++;
                if(max_len==0)
                    max_len=curr_len;
                else
                    max_len=min(max_len,curr_len);
                while(sum>=target && i<nums.size())
                {
                    sum-=nums[i];
                    i++;
                    curr_len--;
                    if(sum>=target)
                        max_len=min(max_len,curr_len);
                }
            }
        }
        return max_len;
    }
};