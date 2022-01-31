class Solution {
public:
    // Sorting the array than finding it their is a repetion in array
    int findDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==nums[i+1])
                return nums[i];
        }
        return 0;
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