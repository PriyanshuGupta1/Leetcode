class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10002;
		vector<int> freq(n, 0),dp(n, 0);
		for (auto i : nums)
            freq[i]++;
        dp[1]=freq[1];
		for (int i=2; i<n; i++)
            dp[i]=max(dp[i-2]+i*freq[i],dp[i-1]);
		return dp[n-1];
    }
};