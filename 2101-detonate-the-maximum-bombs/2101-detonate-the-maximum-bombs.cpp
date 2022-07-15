class Solution {
public:
    int dfs(int x,int y,int r,vector <vector <int> > &bombs,vector <int> &vis)
    {
        int currBomb=0;
        for(int i=0;i<bombs.size();i++)
        {
            // cout<<"I"<<i<<endl;
            if(vis[i] != 1)
            {
                long long x1=bombs[i][0],y1=bombs[i][1];
                long double xt=sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
                if(xt <= r)
                {
                    currBomb++;
                    vis[i]=1;
                    currBomb+=dfs(bombs[i][0],bombs[i][1],bombs[i][2],bombs,vis);
                }
            }
        }
        // cout<<"CurrBomb"<<currBomb<<endl;
        return currBomb;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        // explode each bomb find the bomb that causes most destruction
        // by exploding a bomb explode all the bomb in range of this bomb
        int maxBomb=1;
        for(int i=0;i<bombs.size();i++)
        {
            vector <int> vis(bombs.size(),0);
            vis[i]=1;
            maxBomb=max(maxBomb,1+dfs(bombs[i][0],bombs[i][1],bombs[i][2],bombs,vis));
            // cout<<"MaxBomb"<<maxBomb<<endl;
            vis[i]=0;
        }
        return maxBomb;
    }
};