/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        for(int i=0;i<n;i++)
        {
            int j=0;
            for(;j<n;j++)
            {
                if(i==j || !knows(i,j) && knows(j,i))
                    continue;
                else if(knows(i,j) || !knows(j,i))
                    break;
            }
            if(j==n)
                return i;
        }
        return -1;
    }
};