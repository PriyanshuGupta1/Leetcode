class Solution {
private:
    vector<vector <int>> a;
public:
    void subset(int index,vector <int> &nums,vector <int> t)
    {
        if(index==nums.size())
        {
            a.push_back(t);
            return;
        }
        t.push_back(nums[index]);
        subset(index+1,nums,t);
        t.pop_back();
        subset(index+1,nums,t);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector <int> t;
        subset(0,nums,t);
        return a;
    }
    
};