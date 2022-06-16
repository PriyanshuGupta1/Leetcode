class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> res;
        int prod=1;
        vector <int> left(nums.size(),1),right(nums.size(),1);
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)
            {
                prod*=nums[i-1];
                left[i]=prod;
            }
        }
        prod=1;
        for(int j=nums.size()-1;j>=0;j--)
        {
            if(j!=nums.size()-1)
            {
                prod*=nums[j+1];
                right[j]=prod;
            }
        }
        for(int i=0;i<nums.size();i++)
            res.push_back(left[i]*right[i]);
        return res;
    }
};