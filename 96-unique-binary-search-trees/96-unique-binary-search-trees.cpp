class Solution {
public:
    int numTrees(int n) 
    {
        int g[20]={0};
        g[0]=1;
        g[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                g[i]+=g[j-1]*g[i-j];
            }
        }
        return g[n];
    }
};