class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> person(n+1,0);
        for(auto x:trust)
        {
            person[x[0]]--;
            person[x[1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(person[i]==n-1)
                return i;
        }
        return -1;
    }
};