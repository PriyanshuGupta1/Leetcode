class Solution {
public:
    int bitwiseComplement(int n) 
    {
        int count=0,a=n;
        if(n==0)
            return 1;
        while(n>0)
        {
            n=n>>1;
            count++;
        }
        int sum=pow(2,count)-1;
        return a^sum;
    }
};