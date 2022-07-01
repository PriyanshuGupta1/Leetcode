// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int val,vector <int> &vis,vector <int> adj[],int parent)
    {
        bool res=false;
        for(auto it: adj[val])
        {
            if(it == parent)
                continue;
            if(vis[it])
                return true;
            if(!vis[it])
            {
                vis[it]=1;
                res |= dfs(it,vis,adj,val);
            }
        }
        return res;
    }
    bool isCycle(int n, vector<int> adj[]) {
        vector <int> vis(n,0);
        // map <int,int> mp;
        int res=false;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                res |= dfs(i,vis,adj,-1);
            }
                if(res)
                    return res;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends