class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
        map<int,int> mp;
        int pairs=nums.size()/2,count=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second%2==0)
                count+=it->second/2;
            else
                return false;
        }
        if(count==pairs)
            return true;
        else
            return false;
    }
};