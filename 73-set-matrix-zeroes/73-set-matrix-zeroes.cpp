class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        vector <int> rows;
        vector <int> coloumns;
        int r=matrix.size(),c=matrix[0].size();
        for(int i=0;i<r;i++)    
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.push_back(i);
                    coloumns.push_back(j);
                }
            }
        }
        for(int i=0;i<rows.size();i++)
        {
            int t=rows[i];
            for(int j=0;j<c;j++)
            {
                matrix[t][j]=0;
            }
        }
        for(int i=0;i<coloumns.size();i++)
        {
            int t=coloumns[i];
            for(int j=0;j<r;j++)
            {
                matrix[j][t]=0;
            }
        }
    }
};
