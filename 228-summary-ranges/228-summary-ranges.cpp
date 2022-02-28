class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        string a;
        vector <string > v;
        int j=0;
        for(int i=0;j<nums.size();j++)
        {
            if(j+1<nums.size() && nums[j+1]==nums[j]+1)
                continue;
            if(i==j)
            {
                a=to_string(nums[i]);
                v.push_back(a);
                a.erase();
            }
            else
            {
                a+=to_string(nums[i]);
                a+="->";
                a+=to_string(nums[j]);
                v.push_back(a);
                a.erase();
            }
            i=j+1;
        }
        return v;
    }
};