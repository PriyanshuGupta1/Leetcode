class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int > st;
        if(pushed.size()==0 && popped.size()==0)
            return true;
        else if(pushed.size()==0 || popped.size()==0)
            return false;
        int i=0,j=0;
        st.push(pushed[i]);
        i++;
        while(i<pushed.size() || j<popped.size())
        {
            if(st.empty() && i<pushed.size())
            {
                st.push(pushed[i]);
                i++;
            }
            else if(st.top()!=popped[j] && i<pushed.size())
            {
                st.push(pushed[i]);
                i++;
            }
            else if(!st.empty() && st.top()==popped[j] && j<popped.size())
            {
                st.pop();
                j++;
            }
            else
                return false;
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};