class Solution {
public:
    vector <vector<int>> a;
    void subset(int index,vector <int> &candidates,int target,vector <int> t)
    {
        if(target<0 || index==candidates.size())
            return;
        if(target==0)
        {
            a.push_back(t);
            return;
        }
        t.push_back(candidates[index]);
        subset(index,candidates,target-candidates[index],t);
        t.pop_back();
        subset(index+1,candidates,target,t);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector <int> t;
        subset(0,candidates,target,t);
        return a;    
    }
};