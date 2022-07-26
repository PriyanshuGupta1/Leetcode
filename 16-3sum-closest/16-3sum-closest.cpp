class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int currNum=0,currDiff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i] == nums[i-1] )
                continue; // it will give us the same min difference
            int newTarget=target-nums[i];
            // we will try to find the closest diff to this new target with assuming nums[i] is present
            int left=i+1,right=nums.size()-1;
            while(left < right)
            {
                if(abs(nums[left]+nums[right]-newTarget) < currDiff)
                {
                    currDiff=abs(nums[left]+nums[right]-newTarget);
                    currNum=nums[left]+nums[right]+nums[i];
                }
                if(nums[left]+nums[right]<newTarget)
                    left++;
                else
                    right--;
            }
        }
        cout<<currDiff;
        return currNum;
    }
};