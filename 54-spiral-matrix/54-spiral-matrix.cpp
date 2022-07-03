class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // naive method
        vector <int> v;
        int startingRow=0,endingRow=matrix.size()-1,startingColoumn=0,endingColoumn=matrix[0].size()-1;
        while(startingRow <= endingRow && startingColoumn <= endingColoumn)
        {
            for(int j=startingColoumn;j<=endingColoumn;j++)
                v.push_back(matrix[startingRow][j]);
            for(int i=startingRow+1;i<=endingRow;i++)
                v.push_back(matrix[i][endingColoumn]);
            if(startingRow != endingRow)
            {
                for(int j=endingColoumn-1;j>=startingColoumn;j--)
                    v.push_back(matrix[endingRow][j]);
            }
            if(startingColoumn != endingColoumn)
            {
                for(int i=endingRow-1;i>=startingRow+1;i--)
                    v.push_back(matrix[i][startingColoumn]);
            }
            startingRow++;
            startingColoumn++;
            endingRow--;
            endingColoumn--;
        }
        return v;
    }
};