class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector <vector <int> > res;
        for(int i=0;i<nums.size();i++)
        {
            long long currtarget=target-nums[i];
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int j=i+1;j<nums.size();j++)
            {
                long long newTarget=currtarget-nums[j];
                if(nums[j] == nums[j-1] && i+1 != j)
                    continue;
                int left=j+1,right=nums.size()-1;
                
                while(left<right)
                {
                    if(nums[left]+nums[right] == newTarget)
                    {
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        while( left<right && nums[left] == nums[left-1])
                            left++;
                        right--;
                    }
                    else
                    {
                        if( nums[left] + nums[right] > newTarget )
                            right--;
                        else 
                            left++;
                    }
                }
            }
        }
        return res;
    }
};