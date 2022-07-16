class Solution {
public:
    bool dfs(int i,vector <int> adj[],vector <int> &vis,vector <int> dfsVis,int parent)
    {
        vis[i]=1;
        dfsVis[i]=1;
        for(auto it: adj[i])
        {
            if(vis[it] != 1)
            {
                if(!dfs(it,adj,vis,dfsVis,i))
                    return false;
            }
            if(dfsVis[it] == 1 && it != parent)
                return false;
        }
        dfsVis[i]=0;
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // if there is a loop then, it is not a tree
        // all nodes are connected
        vector <int> adj[n];
        for(int i=0; i<edges.size() ;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector <int> vis(n+1,0),dfsVis(n+1,0);
        if(!dfs(0,adj,vis,dfsVis,-1))
            return false;
        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0)
                return false;
        }
        return true;
    }
};