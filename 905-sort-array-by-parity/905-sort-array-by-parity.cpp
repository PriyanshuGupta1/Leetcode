class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            if(nums[i]&1==1)
            {
                swap(nums[j],nums[i]);
                j--;
            }
            else
                i++;
        }
        return nums;
    }
};