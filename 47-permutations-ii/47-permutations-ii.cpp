class Solution {    
private:
    vector <int> v;
public:
    void recursion(vector <int> &nums,vector <vector <int>>&res,map <int,int> mp)
    {
        if(v.size()==nums.size())
        {
            res.push_back(v);
            return;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==0)
                continue;
            it->second--;
            v.push_back(it->first);
            recursion(nums,res,mp);
            it->second++;
            v.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // aim select a key each time so that we dont produce same permuation
        map <int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        vector <vector <int>> res;
        recursion(nums,res,mp);
        
        return res;
    }
};