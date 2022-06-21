class Solution {
public:
    bool isSafe(int row,int col,vector <string> board)
    {
        int i=row,j=col;
        
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        i=row,j=col;
        
        while(j>=0)
        {
            if(board[i][j]=='Q')
                return false;
            j--;
        }
        i=row,j=col;
        
        while(i<board.size() && j>=0)
        {
            if(board[i][j]=='Q')
                return false;
            i++;
            j--;
        }
        return true;
    }
    void recursion(int col,vector <vector <string>> &res,vector <string> board)
    {
        if(col==board.size())
        {
            res.push_back(board);
            // cout<<col<<" "<<board.size();
            for(int i=0;i<board.size();i++)
            {
                for(int j=0;j<board.size();j++)
                {
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            return;
        }
        
        for(int i=0;i<board.size();i++)
        {
            // cout<<col<<" "<<i;
            if(isSafe(i,col,board))
            {
                board[i][col]='Q';
                recursion(col+1,res,board);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector <vector <string>> res;
        vector <string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        recursion(0,res,board);
        return res;
    }
};