class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map <int,int> umap;
        vector <int> res;
        for(int i=0;i<nums.size();i++)
            umap[nums[i]]++;
        for(auto it=umap.begin();it!=umap.end();it++)
            if(it->second>nums.size()/3)
                res.push_back(it->first);
        return res;
    }
};