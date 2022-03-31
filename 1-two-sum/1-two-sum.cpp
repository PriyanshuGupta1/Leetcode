class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[target-nums[i]]!=0)
            {
                v.push_back(i);
                v.push_back(mp[target-nums[i]]-1);
                break;
            }   
            else 
                mp[nums[i]]=i+1;
        }
        return v;
    }
};
    // Approach 1(Brute Force Technique) 
    // Time complexity: O(N^2)
    // Space Complexity :O(1)
    // vector<int> twoSum(vector<int>& nums, int target) 
    // {
    //     vector <int> v;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         for(int j=i+1;j<nums.size();j++)
    //         {
    //             if(nums[i]+nums[j]==target)
    //             {
    //                 v.push_back(i);
    //                 v.push_back(j);
    //                 break;
    //             }
    //         }
    //     }
    //     return v;
    // }