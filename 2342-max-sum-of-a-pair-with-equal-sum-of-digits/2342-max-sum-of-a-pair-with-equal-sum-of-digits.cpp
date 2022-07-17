class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int maxSum=-1;
        unordered_map <int,int> umap;
        for(int i=0;i<nums.size();i++)
        {
            // cout<<nums[i];
            int digSum=0,t=nums[i];
            while(t>0)
            {
                digSum+=t%10;
                t/=10;
            }
            if(umap[digSum] != 0)
            {
                if(umap[digSum]+nums[i] >maxSum)
                {
                    maxSum=umap[digSum]+nums[i];
                }
            }
            umap[digSum]=max(umap[digSum],nums[i]);
        }
        return maxSum;
    }
};