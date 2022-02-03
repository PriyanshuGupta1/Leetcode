class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map <int,int> un_mp;
        vector <int> v;
        for(int i=0;i<nums.size();i++)
        {
            int findTarget=target-nums[i];
            if(un_mp.find(findTarget)!=un_mp.end())
            {
                cout<<i<<" "<<findTarget;
                v.push_back(un_mp[findTarget]+1);
                v.push_back(i+1);
                return v;
            }
            else
                un_mp[nums[i]]=i;
            
        }
        return v;
    }
};
