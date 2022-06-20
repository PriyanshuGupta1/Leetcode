class Solution {
    // 2*n *n *log n + n *logn 
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector <int>> set;
        sort(nums.begin(),nums.end());
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
            set.insert(v);
        }
        for(auto it:set)
            res.push_back(it);
        return res;
    }
};