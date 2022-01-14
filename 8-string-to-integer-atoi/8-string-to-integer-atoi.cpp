class Solution {
public:
    int myAtoi(string s) 
    {
        int num=0,flag=1,f=0;
        int i=0;
        while(s[i]==' ')
        {
            i++;
        }
        if(s[i]=='+')
        {
            flag=1;
            i++;
        }
        else if(s[i]=='-')
        {
            flag=0;
            i++;
        }
        for(;i<s.length();i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                
                if(num==0)
                    num=s[i]-'0';
                else
                {
                    if(num>INT_MAX/10 ||(num==INT_MAX/10 && s[i]>'7'))
                    {
                        if(flag==0)
                            return INT_MIN;
                        else 
                            return INT_MAX;
                    }   
                    num=num*10;
                    num+=s[i]-'0';
                }
            }
            else if(!(s[i]>=48 && s[i]<=57))
                break;
        }
        if(flag==0)
            num=num*-1;
        return num;
    }
};