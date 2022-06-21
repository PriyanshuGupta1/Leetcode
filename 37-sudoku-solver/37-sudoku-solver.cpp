class Solution {
public:
    bool isPossible(int number,int row,int col,vector<vector<char>>& board)
    {
        char num=number+'0';
        for(int i=0;i<board.size();i++)
        {
            if(board[row][i]==num || board[i][col]==num || board[3*(row/3)+i/3][3*(col/3)+i%3]==num)
                return false;
        }
        return true;
    }
    bool recursion(int i,int j,vector<vector<char>>& board)
    {
        for(int row=0;row<board.size();row++)
        {
            for(int col=0;col<board[0].size();col++)
            {
                if(board[row][col]=='.')
                {
                    for(int num=1;num<10;num++)
                    {
                        if(isPossible(num,row,col,board))
                        {
        
                            board[row][col]=num+'0';
                            if(recursion(i,j+1,board))
                                return true;
                            else
                                board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        //first find blank space
        // if encountered a blank space fill it with 1-9
        // check if the number we want to fill can it be filled or not
        // if true then continue
        // if false find other soln
        // if blank space is not filled revert back
        // when all spaces are filled return true and return the board
        recursion(0,0,board);
    }
};