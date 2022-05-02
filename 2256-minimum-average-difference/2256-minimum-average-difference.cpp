class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum=0,lsum=0,val,lowval=INT_MAX;
        int index=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        for(int i=0;i<nums.size();i++){
            lsum+=nums[i];
            sum-=nums[i];
            if(i<nums.size()-1)
                val=lsum/(i+1)-sum/(nums.size()-i-1);
            else
                val=lsum/(i+1);
            val=abs(val);
            if(lowval>val)
            {
                lowval=val;
                index=i;
            }
        }
        return index;
    }
};