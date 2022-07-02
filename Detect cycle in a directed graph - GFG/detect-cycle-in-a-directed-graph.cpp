// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCyclic(int n, vector<int> adj[]) {
        vector <int> res;
        vector <int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it : adj[i])
                indegree[it]++;
        }
        queue <int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while( !q.empty() )
        {
            int top=q.front();
            q.pop();
            res.push_back(top);
            for(auto it:adj[top])
            {
                indegree[it]--;
                if(!indegree[it])
                    q.push(it);
            }
        }
        // cout<<res.size();
        return res.size()==n ? false :true;
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