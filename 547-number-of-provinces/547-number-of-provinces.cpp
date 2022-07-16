class Solution {
public:
    void bfs(int i,vector<vector<int>>& isConnected, vector <int> &vis)
    {
        queue <int> q;
        q.push(i);
        while( !q.empty() )
        {
            int top=q.front();
            q.pop();
            vis[top]=1;
            for(int j=0;j<isConnected.size();j++)
            {
                if( vis[j] != 1 && top!=j && isConnected[top][j] == 1)
                    q.push(j);
            }
                
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // we have to return the different number of components
        vector <int> vis(isConnected.size()+1,0);
        int count=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(vis[i] != 1)
            {
                bfs(i,isConnected,vis);
                count++;
            }
        }
        return count;
    }
};