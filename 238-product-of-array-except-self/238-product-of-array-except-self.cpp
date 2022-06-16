class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> res(nums.size(),1);
        int prod=1;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)
            {
                prod*=nums[i-1];
                res[i]=prod;
            }
        }
        prod=1;
        for(int j=nums.size()-1;j>=0;j--)
        {
            if(j!=nums.size()-1)
            {
                prod*=nums[j+1];
                res[j]=res[j]*prod;
            }
        }
        return res;
    }
};