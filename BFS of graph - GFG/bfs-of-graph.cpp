// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int val,vector <int> &res,vector <int> &vis,vector <int> adj[])
    {
        queue <int > q;
        q.push(val);
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            vis[top]=1;
            res.push_back(top);
            for(int it : adj[top])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        vector <int> res;
        vector <int> vis(n,0);
        if(!vis[0])
            bfs(0,res,vis,adj);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends