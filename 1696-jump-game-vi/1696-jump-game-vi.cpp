class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        // start jump from index 0 
        // at most k jumps forward
        // return the maximum score
        
        vector <int> dp(nums.size()+1,0);
        dp[0]=nums[0];
        deque <int> q; // we will insert the indexes which will give the highest dp
        q.push_back(0);
        for(int i=1;i<nums.size();i++)
        {
            if(q.front()+k<i)
                q.pop_front(); // if the element at the top is at a distance greater than k than we will remove that element
            dp[i]=nums[i]+dp[q.front()]; //the best result will be at the front
            while(!q.empty() && dp[q.back()]<dp[i])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        return dp[nums.size()-1];
    }
};