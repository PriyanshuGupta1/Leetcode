class Solution {
public:
    // 3 7 2 3
    int recursion(int i,int j,int counter,vector <int> &piles,vector <vector <vector <int>>>&dp)
    {
        if(i>=j)
            return 0;
        if(dp[i][j][counter]!=-1)
            return dp[i][j][counter];
        if(counter)
        {
            return dp[i][j][counter]=max(piles[j]+recursion(i,j-1,0,piles,dp),piles[i]+recursion(i+1,j,0,piles,dp));
        }
        else
        {
            return dp[i][j][counter]=max(-piles[j]+recursion(i,j-1,1,piles,dp),-piles[i]+recursion(i+1,j,1,piles,dp));
        }
    }
    bool stoneGame(vector<int>& piles) {
        vector <vector <vector <int>>> dp (piles.size(),vector <vector <int>>(piles.size(),vector <int>(2,-1)));
        // vector <vector <vector <int>>> dp(prices.size(),vector <vector <int>>(2,vector <int>(3,-1)));
        return recursion(0,piles.size()-1,1,piles,dp)>0 ? 1 : 0;
    }
};