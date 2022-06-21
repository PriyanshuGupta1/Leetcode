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
    void recursion(int col,vector <vector <string>> &res,vector <string> board,vector <int> &lRow,vector <int> &diagUp,vector <int> &diagDown)
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
            if(lRow[i]==0 && diagDown[i+col]==0 && diagUp[board.size()-1+col-i]==0)
            {
                board[i][col]='Q';
                lRow[i]=1;
                diagDown[i+col]=1;
                diagUp[board.size()-1+col-i]=1;
                recursion(col+1,res,board,lRow,diagUp,diagDown);
                lRow[i]=0;
                diagDown[i+col]=0;
                diagUp[board.size()-1+col-i]=0;
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
        vector <int> lRow(n,0),diagUp(2*n-1,0),diagDown(2*n-1,0);
        recursion(0,res,board,lRow,diagUp,diagDown);
        
        return res;
    }
};