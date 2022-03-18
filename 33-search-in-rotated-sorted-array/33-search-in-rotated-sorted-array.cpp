class Solution {
public:
    int search(vector<int>& nums,int target)
    {
        int left=0,right=nums.size()-1,pivot=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                pivot=mid;
                break;
            }    
            if(nums[mid]>=nums[left]){
                if(nums[mid]>=target && nums[left]<=target)
                    right=mid-1;
                else
                    left=mid+1;
            }
            else{
                if(nums[mid]<=target && nums[right]>=target)
                    left=mid+1;
                else
                    right=mid-1;
            }
        }
        return pivot;
    }
};