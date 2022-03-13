class Solution {
public:
    bool isValid(string s) 
    {
        stack <char> st;
        if(s.length()==0)
            return true;
        st.push(s[0]);
        int i=1;
        while(i<s.length())
        {
            if(s[i]=='{'|| s[i]=='(' || s[i]=='[')
                st.push(s[i]);
            if(s[i]==')')
            {
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else
                    return false;
            }
            else if(!st.empty() && s[i]==']')
            {
                if(st.top()=='[')
                    st.pop();
                else
                    return false;
            }
            else if(!st.empty() && s[i]=='}')
            {
                if(st.top()=='{')
                    st.pop();
                else
                    return false;
            }
            i++;
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};