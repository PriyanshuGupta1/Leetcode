class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // brute force solution N*K will give TLE
        vector<int> res;
        int n=nums.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++)
            pq.push({nums[i],i});
        res.push_back(pq.top().first);
        for(int i=k;i<n;i++)
        {
            while(!pq.empty() && i-k>pq.top().second-1 )
                pq.pop();
            pq.push({nums[i],i});
            res.push_back(pq.top().first);
        }
        return res;
    }
};