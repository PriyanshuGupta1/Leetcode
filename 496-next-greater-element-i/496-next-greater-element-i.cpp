class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector <int> a;
        for(int i=0;i<nums1.size();i++)    
        {
            int flag=0,ret=-1;
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                    flag=1;
                if(flag==1 && nums2[j]>nums1[i])
                {
                    ret=nums2[j];
                    break;
                }
            }
            a.push_back(ret);
        }
        return a;
    }
};