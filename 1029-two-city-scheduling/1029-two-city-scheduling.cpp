class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](const vector <int> &a1,const vector <int> &a2){return (a1[0]-a1[1]<a2[0]-a2[1]);});
    int sum=0;
    for(int i=0;i<costs.size()/2;i++)
        sum+=costs[i][0]+costs[i+costs.size()/2][1];
    return sum;
    }
};