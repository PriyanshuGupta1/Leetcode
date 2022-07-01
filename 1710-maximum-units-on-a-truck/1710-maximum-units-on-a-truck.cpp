class Solution {
public:
    static bool comp(const vector <int> &v1,const vector <int> &v2)
    {
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //not a dp quesn 
        //greedy quesn
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int maxUnits=0;
        for(int i=0;i<boxTypes.size();i++)
        {
            // cout<<maxUnits<<endl;
            if(truckSize==0)
                return maxUnits;
            if(truckSize-boxTypes[i][0]>=0)
            {
                maxUnits += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else
            {
                maxUnits += truckSize * boxTypes[i][1];
                return maxUnits;
            }
        }
        return maxUnits;
    }
};