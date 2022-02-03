class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        unordered_map<int,int> m;
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sum=nums1[i]+nums2[j];
                m[sum]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sum= -1*(nums3[i]+nums4[j]);
                if(m.find(sum)!=m.end())
                {
                    count+=m[sum];
                }
            }
        }
        return count;
    }
};