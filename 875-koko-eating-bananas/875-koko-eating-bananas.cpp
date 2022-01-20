class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) 
    {
        int min=1,max=0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]>max)
                max=piles[i];
        }
        cout<<max<<" "<<min;
        while(max>min)
        {
            int middle=(max+min)/2,count=0;
            for(int i=0;i<piles.size();i++)
            {
                count+=(piles[i]/middle)+(piles[i]%middle!=0);
            }
            if(count<=H)
                max=middle;
            else
                min=middle+1;
        }
        return max;
        
    }
};