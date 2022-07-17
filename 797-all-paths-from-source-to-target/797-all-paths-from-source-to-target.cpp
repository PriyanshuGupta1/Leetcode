class Solution {
public:
    void dfs(int index,vector<vector<int>>& graph,vector <int> dfsVis,vector <vector<int>> &res,vector <int> curr)
    {
        if(index==graph.size()-1)
        {
            curr.push_back(index);
            res.push_back(curr);
            return;
        }
        dfsVis[index]=1;
        curr.push_back(index);
        for(auto it:graph[index])
            if(dfsVis[it] !=1)
                dfs(it,graph,dfsVis,res,curr);
        dfsVis[index]=0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // adjacency matrix is given
        // dfs traversal take each route if we find one route to be successfull we will store it in res
        // we will traverse all the path originating from root 
        vector <int> curr,dfsVis(graph.size()+1,0);
        vector <vector <int>> res;
        dfs(0,graph,dfsVis,res,curr);
        return res;
    }
};