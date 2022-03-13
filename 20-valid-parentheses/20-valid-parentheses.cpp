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
            else
            {
                if(st.empty())
                    return false;
                char a=st.top();
                if((s[i]==')' && a=='(') || (s[i]==']' && a=='[' ) || (s[i]=='}' && a=='{'))
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