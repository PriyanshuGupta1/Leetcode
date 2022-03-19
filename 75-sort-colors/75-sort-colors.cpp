class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int i=0,j=nums.size()-1,q=0;
        while(q<=j)
        {
            if(nums[q]==2)
            {
                swap(nums[q],nums[j]);
                j--;
            }
            else if(nums[q]==1)
                q++;
            else
            {
                swap(nums[i],nums[q]);
                i++;
                q++;
            }
        }
        
    }
};