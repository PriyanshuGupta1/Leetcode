class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int rowToSearch=-1;
        for(int i=0;i<matrix.size();i++)    
        {
            rowToSearch=i;
            if(matrix[i][0]>target)
            {
                i--;
                rowToSearch=i;
                break;
            }
            if(matrix[i][0]==target)
                return true;
        }
        if(rowToSearch<0)
            return false;
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[rowToSearch][j]==target)
                return true;
        }
        return false;
    }
};