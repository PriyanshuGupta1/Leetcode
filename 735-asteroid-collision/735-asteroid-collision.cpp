class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;
        int i=0;
        // Case 1:top element and the element we are inserting are in opp directions
        // pop the top and find the element with the max stregnth its strength and direction will be final
        // Case 2:not in opposite directions
        // just push it at the top with no worries
        for(int i=0;i<asteroids.size();i++)
        {
            bool destroyed=false;
            while(!st.empty() && asteroids[i]<0 && st.top()>0)
            {
                if(-asteroids[i]>st.top())
                {
                    st.pop();
                    continue;
                }
                else if(-asteroids[i]==st.top())
                {
                    st.pop();
                    destroyed=true;
                    break;
                }
                else
                {
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed)
                st.push(asteroids[i]);
        }
        vector <int> res(st.size(),0);
        cout<<st.size();
        int n=st.size()-1;
        while(!st.empty())
        {
            // cout<<st.top();
            res[n--]=st.top();
            st.pop();
        }
        return res;
    }
};