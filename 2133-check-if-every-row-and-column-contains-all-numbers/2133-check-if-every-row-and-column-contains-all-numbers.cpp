class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        for(int i=0;i<n;i++)    
        {
            vector <int> a;
            for(int j=0;j<n;j++)
            {
                auto it = std::find(a.begin(), a.end(), matrix[i][j]);
                if(it != a.end())
                    return false;
                else
                    a.push_back(matrix[i][j]);
                    
            }
        }
        for(int i=0;i<n;i++)    
        {
            vector <int> a;
            for(int j=0;j<n;j++)
            {
                auto it = std::find(a.begin(), a.end(), matrix[j][i]);
                if(it != a.end())
                    return false;
                else
                    a.push_back(matrix[j][i]);
            }
        }
        return true;
    }
};