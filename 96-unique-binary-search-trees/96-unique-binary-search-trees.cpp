class Solution {
public:
    int numTrees(int n) 
    {
        long a=1;
        for(int i=0;i<n;i++)
        {
            a=a*2*(2*i+1)/(i+2);
        }
        return (int)a;
    }
};