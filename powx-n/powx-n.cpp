class Solution {
public:
    double binpow(double x,int n)
    {
        if(n==0)    
            return 1;
        double res=binpow(x,n/2);
        if(n&1)
            return res*res*x;
        else
            return res*res;
    }
    double myPow(double x, int n) 
    {
        if(n>0)
            return binpow(x,n);
        else
            return binpow(1/x,abs(n));
    }
    
};