class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)
            return stones[0];
        int leftMax=0,rightMax=0,currSize=stones.size();
        while(currSize>1)
        {
            for(int i=0;i<currSize;i++)
                if(stones[rightMax]<stones[i])
                    rightMax=i;
            swap(stones[rightMax],stones[currSize-1]);
            for(int i=0;i<currSize-1;i++)
                if(stones[leftMax]<stones[i])
                    leftMax=i;
            swap(stones[leftMax],stones[currSize-2]);
            if(stones[currSize-1]==stones[currSize-2])
            {
                currSize-=2;
                leftMax=0; rightMax=0;
            }
            else
            {
                stones[currSize-2]=stones[currSize-1]-stones[currSize-2];
                currSize--;leftMax=0; rightMax=0;
            }
        }
        if(currSize==0)
            return 0;
        else
            return stones[0];
    }
};