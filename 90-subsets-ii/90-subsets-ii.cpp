class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector <int>> set;
        vector <vector <int>> res;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++)
        {
            vector <int> v;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                    v.push_back(nums[j]);
            }  
            sort(v.begin(),v.end());
            set.insert(v);
        }
        for(auto it:set)
            res.push_back(it);
        return res;
    }
};