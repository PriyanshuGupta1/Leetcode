class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> a;
        if(nums.size()<2)
            return a;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size() && nums[i]<=0;i++)
        {
            if(i==0 || nums[i]!=nums[i-1])
            {
                int left=i+1,right=nums.size()-1,target=-nums[i];
                while(left<right)
                {
                    if(nums[left]+nums[right]==target)
                    {
                        a.push_back({nums[left],nums[right],nums[i]});
                        left++;right--;
                        while(left<right && nums[left]==nums[left-1])
                            left++;
                    }
                    else if(nums[left]+nums[right]>target)
                        right--;
                    else
                        left++;
                }   
            }
        }
        return a;
    }
};