class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int fast=nums[0],slow=nums[0];
        do
        {
            fast=nums[nums[fast]];
            slow=nums[slow];
        }while(fast!=slow);
        slow=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
    // Using Hash map
    // int findDuplicate(vector<int>& nums) 
    // {
    //     map<int,int> mp;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         mp[nums[i]]++;
    //         if(mp[nums[i]]>1)
    //             return nums[i];
    //     }
    //     return 0;
    // }
};