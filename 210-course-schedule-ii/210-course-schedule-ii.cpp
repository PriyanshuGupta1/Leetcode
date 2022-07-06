class Solution {
public:
    bool dfs(int val,vector <int> adj[],vector <int> &vis,vector <int> &dfsVis,stack <int> &st)
    {
        vis[val]=1;
        dfsVis[val]=1;
        for(auto it: adj[val])
        {
            if(!vis[it])
                if(!dfs(it,adj,vis,dfsVis,st))
                    return false;
            if(dfsVis[it])
                return false;
            
        }
        st.push(val);
        dfsVis[val]=0;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        stack <int> st;
        vector <int> vis(numCourses,0);
        vector <int> dfsVis(numCourses,0);
        // use dfsVis to check if its a cycle of not
        // we will use stack to store the topological sort
        // if the stack size is diff and not equal to num courses that there is a cycle we will return an empty array 
        // else we will return the topological sorting ans
        vector <int> adj[numCourses];
        vector <int> res;
        for(int i=0;i<prerequisites.size();i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(!dfs(i,adj,vis,dfsVis,st))
                    return res;
                    // there is a cylcle within the graph ,so we returned an empty array
            }
        }
        // cout<<st.size();
        if(st.size() != numCourses)
            return res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }
};