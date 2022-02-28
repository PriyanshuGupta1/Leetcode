class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        string a;
        vector <string > v;
        int i=0;
        for(int j=0;j<nums.size();j++)
        {
            if(j+1<nums.size() && nums[j+1]==nums[j]+1) //nums[j+1]-nums[j]==1 is not taken to avoid overflow 
                continue; //if consecutive range is present we will continue to process the array
            if(i==j)
            {
                a=to_string(nums[i]);//only single element is present with no consecutive element ahead
                v.push_back(a);
                a.erase();
            }
            else
            {
                a+=to_string(nums[i]);//the element where the range started
                a+="->";
                a+=to_string(nums[j]); // the element where the range ended
                v.push_back(a);
                a.erase();
            }
            i=j+1;
        }
        return v;
    }
};