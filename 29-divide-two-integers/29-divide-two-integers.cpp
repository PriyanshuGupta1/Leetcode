class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if((long)dividend/divisor>=INT_MAX)
            return INT_MAX;
        int res=dividend/divisor;
        return res;
    }
};