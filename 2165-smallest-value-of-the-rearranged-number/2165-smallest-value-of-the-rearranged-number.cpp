class Solution {
public:
    long long smallestNumber(long long num) 
    {
        int flag=0;
        if(num>=0)
            flag=1;
        else if(num<0)
            flag=0;
        vector <int> n;
        while(num>0)
        {
            n.push_back(num%10);
            num/=10;
        }
        int w=n.size();
        if(flag==0)
        {
            num=num*-1;
            while(num>0)
            {
                n.push_back(num%10);
                num/=10;
            }
            w=n.size();
            sort(n.begin(),n.end(),greater<int>());
            for(int i=0;i<w;i++)
                num=num*10+n[i];
            return num*(-1);
        }
        else
        {
            sort(n.begin(),n.end());
            int count_0=0;
            cout<<num;
            for(int i=0;i<w;i++)
                if(n[i]==0)
                    count_0++;
            if(count_0>0)
            {
                num=n[count_0];
                for(int i=0;i<count_0;i++)
                    num=num*10+n[i];
                for(int i=count_0+1;i<w;i++)
                    num=num*10+n[i];
            }
            else
            {
                for(int i=0;i<w;i++)
                    num=num*10+n[i];
                
            }
            return num;
        }
        return num;
    }
};