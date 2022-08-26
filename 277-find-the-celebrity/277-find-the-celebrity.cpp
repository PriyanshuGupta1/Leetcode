/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int possibleCeleb=0;
        for(int i=0;i<n;i++)
        {
            if(knows(possibleCeleb,i) )
                possibleCeleb=i;
        }
        for(int i=0;i<n;i++)
        {
            if(possibleCeleb!=i)
            {
                if(!knows(i,possibleCeleb) || knows(possibleCeleb,i))
                    return -1;
            }
        }
        return possibleCeleb;
    }
};