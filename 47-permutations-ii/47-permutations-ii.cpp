class Solution {
private:
    set <vector <int>> st;
    vector <vector <int>> v;
public:
    void recursion(int index,vector <int> &nums)
    {
        if(index==nums.size())
            st.insert(nums);
        for(int i=index;i<=nums.size()-1;i++)
        {
            swap(nums[index],nums[i]);
            recursion(index+1,nums);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        recursion(0,nums);
        for(auto it=st.begin();it!=st.end();it++)
            v.push_back(*it);
        return v;
    }
};