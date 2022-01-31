class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int wealth_cust=0,max_wealth_cust=0;
        for(int i=0;i<accounts.size();i++)
        {
            int wealth_cust=0;
            for(int j=0;j<accounts[i].size();j++)
            {
                wealth_cust+=accounts[i][j];
            }
            max_wealth_cust=max(max_wealth_cust,wealth_cust);
        }
        return max_wealth_cust;
    }
};