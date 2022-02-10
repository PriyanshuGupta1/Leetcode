class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int maxCount=1,currCount=1,index=nums[0];
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                currCount++;
            else
                currCount=1;
            if(currCount>maxCount)
                index=nums[i-1];
            maxCount=max(currCount,maxCount);
            
        }
        return index;
    }
};