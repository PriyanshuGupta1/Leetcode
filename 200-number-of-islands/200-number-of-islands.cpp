class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numOfIsland=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    numOfIsland++;
                    queue <pair <int,int>> q;
                    q.push({i,j});
                    grid[i][j]='2';
                    while(!q.empty())
                    {
                        auto top=q.front();
                        q.pop();
                        int r=top.first,c=top.second;
                        
                        if(r>0 && grid[r-1][c]=='1')
                        {
                            q.push({r-1,c});
                            grid[r-1][c]='2';
                        }
                        if(r<grid.size()-1 && grid[r+1][c]=='1')
                        {
                            q.push({r+1,c});
                            grid[r+1][c]='2';
                        }
                        if(c>0 && grid[r][c-1]=='1')
                        {
                            q.push({r,c-1});
                            grid[r][c-1]='2';
                        }
                        if(c<grid[0].size()-1 && grid[r][c+1]=='1')
                        {
                            q.push({r,c+1});
                            grid[r][c+1]='2';
                        }
                    }
                }
            }
        }
        return numOfIsland;
    }
};