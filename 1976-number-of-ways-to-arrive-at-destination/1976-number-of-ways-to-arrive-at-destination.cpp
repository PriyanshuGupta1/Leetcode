class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // undirected graph
        // start traversal
        // time=weight of the edge
        // store the total weight in a vector
        // sort it and count the least weight frequency
        // issue is traversal
        vector <pair<int,int >> adj[n];
        // creating adjacency list with weights
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});   
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});   
        }
        priority_queue <pair<long long,long long>,vector <pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        vector <long long> dis(n+1,1e15);
        vector <long long> dp(n+1,0);
        dp[0]=1;
        int mod=10e8+7;
        while( !pq.empty() )
        {
            long long top=pq.top().second;
            long long wt=pq.top().first;
            pq.pop();
            for(auto it:adj[top])
            {
                if(wt+it.second == dis[it.first])
                {
                    dp[it.first]=(dp[it.first]+dp[top])%mod;
                }
                else if(wt+it.second < dis[it.first])
                {
                    dp[it.first]=dp[top]%mod;
                    dis[it.first]=wt+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }
        return dp[n-1];
    }
};