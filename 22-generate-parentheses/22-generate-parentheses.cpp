class Solution {
public:
    
    void recursion(int openParanthesis,int closeParanthesis,int n,string &t,vector <string> &res)
    {
        if( openParanthesis == n && closeParanthesis == n )
        {
            res.push_back(t);
            return;
        }
        if( openParanthesis < n)
        {
            t+='(';
            recursion(openParanthesis+1,closeParanthesis,n,t,res);
            t.pop_back();
        }
        if( openParanthesis > closeParanthesis)
        {
            t+=')';
            recursion(openParanthesis,closeParanthesis+1,n,t,res);
            t.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        // Your code goes here 
        vector <string> res;
        string t;
        recursion(0,0,n,t,res);
        return res;
    }
};