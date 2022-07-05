class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // naive approach
        // sort the array then check the length for the longest consecutive sequence
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        int max_len=1,curr_len=1;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=nums.size()-1 && nums[i]+1==nums[i+1])
            {
                curr_len++;
                max_len=max(curr_len,max_len);
            }
            else if(i!=nums.size()-1 && nums[i]==nums[i+1])
                continue;
            else
                curr_len=1;
        }
        return max_len;
        // Approach 2
        // store each element in map 
        // traverse the mp and finds it longest consecutive sequence
        
        
    }
};