class Solution 
{
public:
    int binarysearch(vector <int > &nums,int left,int right,int target)
    {
        if(left>right)
            return -1;
        int mid=left+(right-left)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target)
            return binarysearch(nums,left,mid-1,target);
        else
            return binarysearch(nums,mid+1,right,target);
    }
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector <int > a;
        if(nums.size()==0)
        {
            a.push_back(-1);
            a.push_back(-1);
            return a;
        }
        int found=binarysearch(nums,0,nums.size()-1,target);
        if(found==-1)
        {
            a.push_back(-1);
            a.push_back(-1);
            return a;
        }
        else
        {
            int i=found,j=found;
            for(;j>=0;j--)
            {
                if(nums[j]!=target)
                    break;
            }
            a.push_back(j+1);
            for(;i<nums.size();i++)
            {
                if(nums[i]!=target)
                    break;
            }
            a.push_back(i-1);
        }
        return a;
    }
};