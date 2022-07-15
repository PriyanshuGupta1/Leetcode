// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool dfs(int i,int j ,vector <vector <int>> &grid)
    {
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1 || grid[i][j] == 0)
            return false;
        // cout << i << " " << j << endl;
        if( grid[i][j] == 2)
            return true;
        grid[i][j]=0;
        return dfs(i+1,j,grid) || dfs(i,j+1,grid) || dfs(i-1,j,grid) || dfs(i,j-1,grid);
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    if(dfs(i,j,grid))
                        return true;
                    else 
                        return false;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends