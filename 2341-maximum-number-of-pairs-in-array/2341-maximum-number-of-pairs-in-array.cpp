class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map <int,int> umap;
        vector <int> res;
        for(int i=0;i<nums.size();i++)
            umap[nums[i]]++;
        int pairs=0,left=0;
        for(auto it=umap.begin();it!=umap.end();it++)
        {
            pairs+=it->second/2;
            left+=it->second%2;
        }
        res.push_back(pairs);
        res.push_back(left);
        return res;
    }
};