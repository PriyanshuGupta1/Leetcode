class Solution {
public:
    int countEven(int num) 
    {
        int count=0;
        for(int i=1;i<=num;i++)
        {
            int t=i,sum=0;
            while(t>0)
            {
                sum+=t%10;
                t=t/10;
            }
            if(sum%2==0)
                count++;
        }
        return count;
    }
};