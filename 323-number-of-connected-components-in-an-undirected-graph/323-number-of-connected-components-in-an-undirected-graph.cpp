class Solution {
public:
    void bfs(int i,vector <int> adj[],vector <int> &vis)
    {
        queue <int> q;
        q.push(i);
        while( !q.empty() )
        {
            int top=q.front();
            q.pop();
            vis[top]=1;
            for(auto it:adj[top] )
            {
                if(vis[it] != 1)
                    q.push(it);
            }
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
                bfs(i,adj,vis);
                count++;
            }
        }
        return count;
    }
};