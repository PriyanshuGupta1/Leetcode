class Solution {
public:
    void bfs(int i,vector <int> adj[], vector <int> &vis)
    {
        queue <int> q;
        q.push(i);
        while( !q.empty() )
        {
            int top=q.front();
            q.pop();
            vis[top]=1;
            for( auto it: adj[top] )
                if( vis[it] != 1)
                    q.push(it);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // we have to return the different number of components
        vector <int> adj[isConnected.size()+1];
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if( i != j )
                {
                    if(isConnected[i][j] == 1)
                    {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
        }
        vector <int> vis(isConnected.size()+1,0);
        int count=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(vis[i] != 1)
            {
                bfs(i,adj,vis);
                count++;
            }
        }
        return count;
    }
};