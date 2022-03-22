class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1,curr_low=INT_MAX;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<curr_low)
                curr_low=nums[mid];
            if(nums[mid]>=nums[left] && nums[mid]>nums[right])
                left=mid+1;
            else
                right=mid-1;
        }
        return curr_low;
    }
};