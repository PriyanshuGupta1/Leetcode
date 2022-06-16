class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> res;
        int prod=1;
        for(int i=0;i<nums.size();i++)
            prod*=nums[i];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                int curr=1;
                for(int j=0;j<nums.size();j++)
                {
                    if(i!=j)
                        curr*=nums[j];
                }
                res.push_back(curr);
            }
            else
                res.push_back(prod/nums[i]);
        }
        return res;
    }
};