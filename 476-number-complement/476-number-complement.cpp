class Solution {
public:
    int findComplement(int num) 
    {
        int a=1,num1=num;
        while(num1>0)    
        {
            num1=num1>>1;
            if(num1>0)
                a=(a<<1)+1;
        }
        return num^a;
    }
};