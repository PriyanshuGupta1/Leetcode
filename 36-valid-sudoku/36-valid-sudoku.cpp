class Solution {
public:
    bool isValid(char ele,int row,int col,vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            if(i != col && board[row][i]==ele )
                return false;
            if(i != row && board[i][col]==ele) 
                return false;
            if(3*(row/3)+i/3!=row && 3*(col/3)+i%3!= col && board[3*(row/3)+i/3][3*(col/3)+i%3]==ele)
                return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // first iterate through the entire sudoku
        // if we encounter a number we will search the entire row ,coloumn and that block and if found that number to exist it means :not valid
        //for all num if there is no problem return true;
        for(int row=0;row<board.size();row++)
        {
            for(int col=0;col<board[0].size();col++)
            {
                if(board[row][col] != '.')
                {
                    if(isValid(board[row][col],row,col,board))
                        continue;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};