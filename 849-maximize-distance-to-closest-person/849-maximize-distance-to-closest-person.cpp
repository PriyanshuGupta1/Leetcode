class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int neq=-1,n2=-1,diff=0,n=seats.size(),count_1=0;
        for(int i=0;i<n;i++)    
        {
            if(seats[i]==1 && neq==-1)
            {
                diff=max(diff,2*i);
                cout<<i<<" ";
                neq=i;
            }
            if(seats[i]==1)
            {
                diff=max(diff,i-neq);
                neq=i;
                count_1++;
            }
            
        }
        if(count_1==1)
        {
            return max(n-neq-1,neq);
        }
        if(neq<n)
        {
            if(diff/2<=n-neq-1)
            {
                cout<<n-neq-1;
                return (n-neq-1);
            }
        }
        return diff/2;
    }
};