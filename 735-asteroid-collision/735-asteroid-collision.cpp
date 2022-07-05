class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;
        int i=0;
        // Case 1:top element and the element we are inserting are in opp directions
        // pop the top and find the element with the max stregnth its strength and direction will be final
        // Case 2:not in opposite directions
        // just push it at the top with no worries
        while(i<asteroids.size())
        {
            // cout<<i;
            if(st.empty())
                st.push(asteroids[i]);
            else
            {
                int strengthTop=st.top(),strengthCurr=abs(asteroids[i]-0),directionTop=-1,directionCurr=-1;
                strengthTop>0 ? directionTop=1 :directionTop=-1;
                asteroids[i]>0 ? directionCurr=1 :directionCurr =-1;
                if(directionTop==directionCurr)
                {
                    //they are in same direction no issue
                    st.push(asteroids[i]);
                }
                else
                {
                    //they are in opposite direction and should be incoming to each other as well and not away from each other
                    //there can be many bellow in opp direction as well
                    if(strengthTop==strengthCurr)
                            st.pop();
                    else
                    {
                        while(!st.empty())
                        {    
                            int strengthTop=st.top(),directionTop=-1;
                            if(strengthTop>0)
                                directionTop=1;
                            if(strengthTop==strengthCurr && directionTop!=directionCurr && directionCurr==-1)
                            {
                                st.pop();   
                                break;
                            }
                            else if(strengthTop < strengthCurr && directionTop!=directionCurr && directionCurr==-1)
                            {
                                st.pop();   
                                if(st.empty())
                                {
                                    st.push(asteroids[i]);
                                    break;
                                }
                                continue;
                            }
                            else if(strengthTop >strengthCurr && directionTop!=directionCurr && directionCurr==-1)
                            {
                                //destroyed
                                break;
                            }
                            else 
                            {
                                st.push(asteroids[i]);
                                break;
                            }
                        }    
                    }   
                }
            }
            i++;
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