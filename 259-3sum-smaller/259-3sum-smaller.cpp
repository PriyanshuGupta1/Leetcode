class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count=0;
        // sorted or not
        // duplicates are present or not
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size();i++)
        {
            int newTarget=target-nums[i];
            int left=i+1,right=nums.size()-1;
            
            while(left<right)
            {
                if(nums[left]+nums[right]<newTarget)
                {
                    count+=right-left;
                    left++;
                }
                else
                    right--;
                // what should be the condition that now it should move left to find 3 sum pair as well
            }
        }
        return count;
    }
};