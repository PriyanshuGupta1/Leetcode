class Solution {
public:
    vector <vector <int>> res;
    vector <int> t;
    void recursion(int index,vector <int> &candidates,int target)
    {
        if(target==0)
        {
            res.push_back(t);
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i]==candidates[i-1])
                continue;
            if(candidates[index]>target)
                break;
            t.push_back(candidates[i]);
            recursion(i+1,candidates,target-candidates[i]);
            t.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)    {
        sort(candidates.begin(),candidates.end());
        recursion(0,candidates,target);
        return res;
    }
};