class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Approach 2
        // store unique element in set 
        // traverse the set and finds it longest consecutive sequence
        unordered_set<int> st;
        int max_len=0;
        for(int i=0;i<nums.size();i++)
            st.insert(nums[i]);
        for(int i=0;i<nums.size();i++)
        {
            if(!st.count(nums[i]-1))
            {
                int len=1;
                int val=nums[i];
                while(st.count(val+1))
                {
                    len++;
                    val++;
                }
                max_len=max(len,max_len);
            }
        }
        return max_len;
    }
};