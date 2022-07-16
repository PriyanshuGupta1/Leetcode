class Solution {
public:
    void dfs(int i,vector <int> adj[],vector <int> &vis)
    {
        vis[i]=1;
        for(auto it: adj[i])
        {
            if(vis[it] != 1)
                dfs(it,adj,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector <int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int count=0;
        vector <int> vis(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i] != 1)
            {
                dfs(i,adj,vis);
                count++;
            }
        }
        return count;
    }
};