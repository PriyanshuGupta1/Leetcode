class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int inCorrectPairs=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                if(inCorrectPairs>=1)
                    return false;
            inCorrectPairs++;  
            if(i<2 || nums[i-2]<=nums[i])
                nums[i-1]=nums[i];
            else
                nums[i]=nums[i-1];
            }
        }
        return true;
    }
};