class Solution {
public:

    bool canJump(vector<int>& nums) 
    {
        int last=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i+nums[i]>=last)
                last=i;
        }
        if(last==0)
            return true;
        else 
            return false;
    }
};
    // bool jump(vector <int> &nums,int j)
    // {
    //     if(j>nums.size()-1)
    //         return false;
    //     if(j==nums.size()-1)
    //         return true;
    //     bool a=false;
    //     for(int i=nums[j];i>0;i--)
    //     {
    //         a=a||jump(nums,j+i);
    //         if(a==true)
    //             return true;
    //     }
    //     return a;
    // }