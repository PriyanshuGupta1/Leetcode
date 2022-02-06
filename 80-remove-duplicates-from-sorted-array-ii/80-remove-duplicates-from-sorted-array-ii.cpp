class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int count=2;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                count--;
            else
                count=2;
            if(count<=0)
            {
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};