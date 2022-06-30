// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int val,vector <int> &vis,vector <int> adj[] )
    {
        vis[val]=1;
        queue <pair<int,int>> q;
        q.push({val,-1});
        while(!q.empty())
        {
            // cout<<"a";
            auto a=q.front();
            int curr=a.first;
            int parent=a.second;
            // cout<<curr<<" "<<parent<<endl;
            q.pop();
            vis[curr]=1;
            for(auto it: adj[curr])
            {
                if(it==parent)
                    continue;
                else if(vis[it])
                {
                    // cout<<it<<" "<<curr <<" "<< parent<<" "<<endl;
                    return true;
                }
                else
                {
                    if(!vis[it])
                    {
                        q.push({it,curr});
                        vis[val]=1;
                    }
                }
            }        
        }
        return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
        vector <int> vis(n,0);
        // map <int,int> mp;
        int res=false;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                res |= bfs(i,vis,adj);
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