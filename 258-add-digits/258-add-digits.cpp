class Solution {
public:
    int addDigits(int num) 
    {
        int n=0;
        while(num>0)
        {
            n+=num%10;
            num/=10;
            if(num==0 && n>9)
            {
                num=n;
                n=0;
            }
        }
        return n;
    }
    
};