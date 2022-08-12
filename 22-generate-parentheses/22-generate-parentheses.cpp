class Solution {
public:
    bool checkParanthesis(string &t)
    {
        stack <char> st;
        for(int i=0;i<t.length();i++)
        {
            if(t[i] == '(')
                st.push('(');
            else
            {
                if( !st.empty() && st.top() =='(')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();  
    }
    void recursion(int openParanthesis,int closeParanthesis,string t,vector <string> &res)
    {
        if( closeParanthesis - openParanthesis < 0 || openParanthesis < 0 || closeParanthesis < 0 )
            return;
        if(openParanthesis == 0 && closeParanthesis == 0)
        {
            if(checkParanthesis(t))
            {
                res.push_back(t);                
                return;
            }
            else
                return;
        }
        t+='(';
        recursion(openParanthesis-1,closeParanthesis,t,res);
        t.pop_back();
        t+=')';
        recursion(openParanthesis,closeParanthesis-1,t,res);
    }
    vector<string> generateParenthesis(int n) {
        // Your code goes here 
        vector <string> res;
        string t;
        recursion(n,n,t,res);
        return res;
    }
};