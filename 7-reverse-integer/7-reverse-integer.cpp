class Solution {
public:
    int reverse(int num) 
    {
        int flag=0,rev=0,t;    
        if(num<0)
        {
            flag=1;
            if(num==INT_MIN)
                return 0;
            num=num*-1;
        }
        while(num>0)
        {
            if(rev==0)
                rev=num%10;
            else
            {
                if(rev>INT_MAX/10)
                    return 0;
                rev=rev*10+num%10;   
            }
            num/=10;
        }
        if(flag==1)
            return rev*-1;
        return rev;
    }
};