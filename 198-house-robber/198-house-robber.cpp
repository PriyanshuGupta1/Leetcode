class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int prev_1=nums[0],prev_2=0;
        for(int i=1;i<nums.size();i++){
            int left=nums[i];
            if(i>1)
                left+=prev_2;
            int right=prev_1;
            int temp=max(left,right);
            prev_2=prev_1;
            prev_1=temp;
        }
        return prev_1;
    }
    
};