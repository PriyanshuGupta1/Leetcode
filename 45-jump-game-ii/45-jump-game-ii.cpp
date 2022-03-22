class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int steps=0,last=nums.size()-1,curr_max=nums.size()-1;
        while(last>0)
        {
            for(int i=last-1;i>=0;i--)
                if(i+nums[i]>=last && i<curr_max)
                    curr_max=i;
            last=curr_max;
            steps++;
        }
        return steps;
    }
    
};