class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector <int> min_ele,eqe_ele,gre_ele;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
                min_ele.push_back(nums[i]);
            else if(nums[i]>pivot)
                gre_ele.push_back(nums[i]);
            else
                eqe_ele.push_back(nums[i]);
        }
        nums.clear();
        for(int i=0;i<min_ele.size();i++)
            nums.push_back(min_ele[i]);
        for(int i=0;i<eqe_ele.size();i++)
            nums.push_back(eqe_ele[i]);
        for(int i=0;i<gre_ele.size();i++)
            nums.push_back(gre_ele[i]);
        return nums;
    }
};