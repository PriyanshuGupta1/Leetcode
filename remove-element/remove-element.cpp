class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int count=0,j=0,t=nums.size();
        for(int i=0;i<nums.size();i++)    
        {
            if(val==nums[i])
                count++;
        }
        for(int i=0;i<nums.size() && j!=count;i++)
        {
            if(val==nums[i])
            {
                for(int k=i;k<nums.size()-1;k++)
                {
                    nums[k]=nums[k+1];
                }
                j++;
                i--;
            }
        }
        return t-count;
    }
};