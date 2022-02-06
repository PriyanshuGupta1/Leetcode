class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) 
    {
        vector <int> l1,l2;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
                l1.push_back(nums[i]);
            else
                l2.push_back(nums[i]);
        }
        sort(l1.begin(),l1.end());
        sort(l2.begin(),l2.end(),greater <int>());
        nums.clear();
        int count1=0,count2=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                nums.push_back(l1[count1]);
                count1++;
            }
            else
            {
                nums.push_back(l2[count2]);
                count2++;
            }    
        }
        return nums;
    }
};