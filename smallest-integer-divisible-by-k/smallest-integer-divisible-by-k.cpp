class Solution {
public:
    int smallestRepunitDivByK(int k) 
    {
        long long n=1,len=1;
        if(k%2==0 || k%5==0)     
            return -1;
        while(n%k!=0 && k>=len)
        {
            if(n%k==0)
                return len;
            else
            {
                n=n*10+1;
                n=n%k;
                len++;
            }
        }
        if(n%k==0)
            return len;
        return -1;
    }
};