// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checkCycle(int val,vector <int> adj[],vector <int> &vis,vector <int> &dfsvis)
    {
        vis[val]=1;
        dfsvis[val]=1;
        for(auto it : adj[val])
        {
            if(!vis[it])
            {
                if(checkCycle(it,adj,vis,dfsvis))
                    return true;
            }
            else if(dfsvis[it])
                return true;
        }
        dfsvis[val]=0;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        vector <int> vis (n,0);
        vector <int> dfsvis (n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                if(checkCycle(i,adj,vis,dfsvis))
                    return true;
        }
        return false;
    }
    
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends