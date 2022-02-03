class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                v.push_back(m[target-nums[i]]);
                v.push_back(i);
                return v;
            }
            else
                m[nums[i]]=i;
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