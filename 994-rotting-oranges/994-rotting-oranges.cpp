class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // we will traverse the whole grid when we find a rotten orange we will start BFS and if it is a fresh orange it will be made rot
        // issue there could be more than one rotten oranges ,if that exist than it will be contradictory
        // all the rotten oranges have to implement BFS not one at a time ***IMP***
        queue <pair<int,pair<int,int>>> q;
        //{ 1,{2,3}} 1->time,2-> x coordinate 3->y coordinate
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j] == 2)
                    q.push({0,{i,j}});
        int maxTime=0;
        while( !q.empty() )
        {
            auto top=q.front();
            q.pop();
            int time=top.first;
            maxTime=max(maxTime,time);
            int x=top.second.first,y=top.second.second;
            // cout << x << " " << y <<endl; 
            if(x>0 && grid[x-1][y] == 1)
            {
                q.push({time+1,{x-1,y}});
                grid[x-1][y]=2;
            }
            if(y>0 && grid[x][y-1] == 1)
            {
                q.push({time+1,{x,y-1}});
                grid[x][y-1]=2;
            }
            if(x<grid.size()-1 && grid[x+1][y] == 1)
            {
                q.push({time+1,{x+1,y}});
                grid[x+1][y]=2;
            }
            if(y<grid[0].size()-1 && grid[x][y+1] == 1)
            {
                q.push({time+1,{x,y+1}});
                grid[x][y+1]=2;
            }
        }
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j] == 1)
                    return -1;
        return maxTime;
    }
};