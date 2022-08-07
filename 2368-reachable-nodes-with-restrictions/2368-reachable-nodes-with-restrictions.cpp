class Solution {
public:
    void dfs(int val,vector <int> &vis,vector <int> adj[],unordered_map<int,int> &mp,int &res)
    {
        vis[val]=1;
        for(auto it:adj[val])
        {
            if(vis[it] == 0 && mp[it] == 0)
            {
                dfs(it,vis,adj,mp,res);
                res++;
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map <int,int> mp;
        vector <int> adj[n+1];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<restricted.size();i++)
            mp[restricted[i]]++;
        vector <int> vis(n+1,0);
        int res=1;
        dfs(0,vis,adj,mp,res);
        
        return res;
    }
};