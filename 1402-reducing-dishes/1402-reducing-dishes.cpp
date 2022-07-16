class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // sort the array 
        sort(satisfaction.begin(),satisfaction.end());
        int cumSum=0;
        int ans=0;
        int cur=0;
        for(int i = satisfaction.size()-1;i>=0;i--)
        {
            cur += cumSum+satisfaction[i];
            cumSum+=satisfaction[i];
            ans=max(ans,cur);
        }
        return ans;
    }
};