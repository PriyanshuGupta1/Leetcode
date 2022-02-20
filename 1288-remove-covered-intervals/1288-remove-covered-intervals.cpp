class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res=0,l=-1,r=-1;
        sort(intervals.begin(), intervals.end());
        for (auto& v: intervals) 
        {
            if (v[0]>l && v[1]>r) 
            {
                l=v[0];
                ++res;
            }
            r=max(r, v[1]);
        }
        return res;
    }
};