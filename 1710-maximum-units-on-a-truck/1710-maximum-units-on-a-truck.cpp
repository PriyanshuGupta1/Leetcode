class Solution {
public:
    static bool comp(const pair <int,int> &v1,pair <int,int> &v2)
    {
        return v1.second>v2.second;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //not a dp quesn 
        //greedy quesn
        vector <pair <int,int>> v;
        for(int i=0;i<boxTypes.size();i++)
        {
            v.push_back({boxTypes[i][0],boxTypes[i][1]});
        }
        sort(v.begin(),v.end(),comp);
        int maxUnits=0;
        for(int i=0;i<v.size();i++)
        {
            // cout<<maxUnits<<endl;
            if(truckSize==0)
                return maxUnits;
            if(truckSize-v[i].first>=0)
            {
                maxUnits += v[i].first*v[i].second;
                truckSize -= v[i].first;
            }
            else
            {
                maxUnits += truckSize * v[i].second;
                return maxUnits;
            }
        }
        return maxUnits;
    }
};