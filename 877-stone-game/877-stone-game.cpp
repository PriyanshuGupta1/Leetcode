class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector <vector <vector <int>>> dp (n+1,vector <vector <int>>(n+1,vector <int>(2,0)));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int counter=0;counter<2;counter++)
                {
                    if(i>=j)
                        dp[i][j][counter]=0;
                    else
                    {
                        if(counter==1)
                        {
                            dp[i][j][counter]=max(piles[j]+dp[i][j-1][0],piles[i]+dp[i+1][j][0]);
                        }
                        else
                        {
                            dp[i][j][counter]=max(-piles[j]+dp[i][j-1][1],-piles[i]+dp[i][j-1][1]);
                        }
                    }
                }
            }
        }
        return dp[0][n-1][1]>0 ? 1 : 0;
    }
};