// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    void dfs(int val,vector <int> &res,vector <int> &vis,vector <int> adj[])
    {
        res.push_back(val);
        vis[val]=1;
        for(auto it : adj[val]){
            if(!vis[it]){
                dfs(it,res,vis,adj);
            }
        }
    }
  public:
    
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        vector <int> res;
        vector <int> vis(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,res,vis,adj);
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends