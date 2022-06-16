class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod=nums[0],min_prod=nums[0],res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int temp;
            temp=max(nums[i],max(nums[i]*max_prod,nums[i]*min_prod));
            min_prod=min(nums[i],min(nums[i]*max_prod,nums[i]*min_prod));
            max_prod=temp;
            res=max(res,max_prod);
        }
        return res;
    }
};