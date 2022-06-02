class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> temp;
        
        // sort(nums.begin(),nums.end());
        temp.push_back(nums[0]);
        int len=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
                len++;
            }
            else
            {
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};