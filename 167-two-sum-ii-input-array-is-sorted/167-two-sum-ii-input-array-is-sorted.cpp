class Solution {
public:
    // Approach 2: Using two pointer Approach
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector <int> v;
        int left=0,right=numbers.size()-1;
        while(left<right)
        {
            int curr_sum=numbers[left]+numbers[right];
            if(curr_sum==target)
            {
                v.push_back(left+1);
                v.push_back(right+1);
                return v;
            }
            else if(curr_sum>target)
                right--;
            else
                left++;
            
        }
        return v;
    }
};
//     Approach 1: using unordered map
//     Time complexity :O(N^2)
//     Space Complexity : O(N)
//     vector<int> twoSum(vector<int>& nums, int target) 
//     {
//         unordered_map <int,int> un_mp;
//         vector <int> v;
//         for(int i=0;i<nums.size();i++)
//         {
//             int findTarget=target-nums[i];
//             if(un_mp.find(findTarget)!=un_mp.end())
//             {
//                 cout<<i<<" "<<findTarget;
//                 v.push_back(un_mp[findTarget]+1);
//                 v.push_back(i+1);
//                 return v;
//             }
//             else
//                 un_mp[nums[i]]=i;
            
//         }
//         return v;
//     }