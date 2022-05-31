class Solution {
public:
    bool recursion(int i,int j,string s,string p,vector <vector <int>> &dp)
    {
        // cout<<i <<" "<<j<<endl;
        if(i<0 && j<0)
            return true;
        if(j==0 && i>0)
            return false;
        if(j>=0 && i<0 )
        {
            for(int k=j;k>-1;k--)
            {
                if(p[k]=='*')
                    continue;
                else
                    return false;
            }
            return true;
        }
         if(dp[i][j] != -1)
            return dp[i][j];
        if( s[i]==p[j] || p[j]=='?')
        {
            return dp[i][j]=recursion(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*')
        {
            return dp[i][j]=recursion(i-1,j,s,p,dp) | recursion(i,j-1,s,p,dp) ;
        }
        return false;
            
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector <vector <int>> dp(n+1,vector <int>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]=='*')
                dp[0][i]=1;
            else
                break;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if( s[i-1]==p[j-1] || p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                if(p[j-1]=='*')
                {
                    dp[i][j]= dp[i-1][j] | dp[i][j-1] ;
                }
            }
        }
        return dp[n][m];
    }
};