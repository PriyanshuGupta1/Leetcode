class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) 
    {
        int count=0,freq=0;
        vector<int> a;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
                freq++;
            if(nums[i]<target)
                count++;
        }
        for(int i=0;i<freq;i++)
            a.push_back(count++);
        return a;
    }
};