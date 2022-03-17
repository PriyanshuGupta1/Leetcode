class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        stack <int > st;
        st.push(0);
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                st.push(0);
            else if(s[i]==')')
            {
                int t=st.top();
                st.pop();
                int z=st.top();
                st.pop();
                st.push(z+max(2*t,1));
            }
        }
        return st.top();
    }
};