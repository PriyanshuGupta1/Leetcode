class Solution {
public:
    bool dfs(int val,vector <int> adj[],vector <int> &vis,vector <int> &dfsVis)
    {
        vis[val]=1;
        dfsVis[val]=1;
        for(auto it: adj[val])
        {
            cout<<it<<" ";
            if(!vis[it])
            {
                if(!dfs(it,adj,vis,dfsVis))
                    return false;
            }
            else if(dfsVis[it]==1)
                return false;
        }
        dfsVis[val]=0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> adj[numCourses+1];
        for(int i=0;i<prerequisites.size();i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
    
        vector <int> vis(numCourses+1,0);
        vector <int> dfsVis(numCourses+1,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(!dfs(i,adj,vis,dfsVis))
                    return false;
            }
        }
        return true;
    }
};