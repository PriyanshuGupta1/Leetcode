class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        map <int,int> mp;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            int k1=nums[i]+k;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]==k1)
                {
                    if(mp[k1]==0)
                    {
                        count++;
                        mp[k1]=1;
                    }    
                    
                    break;
                }
                if(k1<nums[j])
                    break;
            }
        }
        return count;
    }
};