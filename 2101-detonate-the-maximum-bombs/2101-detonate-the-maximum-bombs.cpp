class Solution {
public:
    int dfs(int index,vector <int> &vis,vector <int> adj[])
    {
        int currBomb=0;
        for(auto it : adj[index]) 
        {
            if(vis[it] != 1)
            {
                currBomb++;
                vis[it]=1;
                currBomb+=dfs(it,vis,adj);
            }
        }
        // cout<<"CurrBomb"<<currBomb<<endl;
        return currBomb;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        // explode each bomb find the bomb that causes most destruction
        // by exploding a bomb explode all the bomb in range of this bomb
        int maxBomb=1;
        vector <int> adj[bombs.size()];
        for(int i=0;i<bombs.size();i++)
        {
            int x=bombs[i][0],y=bombs[i][1],r=bombs[i][2];
            for(int j=0;j<bombs.size();j++)
            {
                if(i!=j)
                {
                    long long x1=bombs[j][0],y1=bombs[j][1];
                    long double xt=sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
                    if(xt <= r )
                        adj[i].push_back(j);
                }
            }
        }
        for(int i=0;i<bombs.size();i++)
        {
            vector <int> vis(bombs.size(),0);
            vis[i]=1;
            maxBomb=max(maxBomb,1+dfs(i,vis,adj));
            // cout<<"MaxBomb"<<maxBomb<<endl;
            vis[i]=0;
        }
        return maxBomb;
    }
};