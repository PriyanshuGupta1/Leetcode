class Solution 
{
public:
    int minMoves(int target, int maxDoubles) 
    {
        int count=0;
        while(target!=1)    
        {
            if(maxDoubles==0)
            {
                cout<<"a";
                return target+count-1;
            }
            if(target%2==0 && maxDoubles>=1 && target/2>=1)
            {
                maxDoubles--;
                cout<<maxDoubles;
                target/=2;
            }
            else
                target--;
            count++;
        }
        return count;
    }
};