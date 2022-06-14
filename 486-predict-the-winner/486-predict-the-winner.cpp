class Solution {
public:
    int recursion(int counter,int start,int end,vector <int> & nums)
    {
        if(start>end)
            return 0;
        if(counter%2==1)
            return max(nums[start]+recursion(counter+1,start+1,end,nums),nums[end]+recursion(counter+1,start,end-1,nums));
        else
           return min(-nums[start]+recursion(counter+1,start+1,end,nums),-nums[end]+recursion(counter+1,start,end-1,nums));
    }
    bool PredictTheWinner(vector<int>& nums) {
        return recursion(1,0,nums.size()-1,nums)>=0 ? 1:0;
    }
};