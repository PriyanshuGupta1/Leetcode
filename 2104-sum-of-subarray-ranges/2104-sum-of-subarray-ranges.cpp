class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // brute-force approach
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            int maxi=INT_MIN,mini=INT_MAX;
            for(int j=i;j<nums.size();j++)
            {
                maxi=max(maxi,nums[j]);
                mini=min(mini,nums[j]);
                sum+=maxi-mini;
            }
        }
        return sum;
    }
};