class Solution {
private:
    vector <vector <int>>res;
    vector <int> v;
public:
    void recursion(int index,vector <int> &nums)
    {
        if(index>nums.size())
            return;
        res.push_back(v);
        for(int i=index;i<nums.size();i++)
        {
            if(i>index && nums[i]==nums[i-1])
                continue;
            v.push_back(nums[i]);
            recursion(i+1,nums);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector <int>> set;
        sort(nums.begin(),nums.end());
        recursion(0,nums);
        return res;
    }
};