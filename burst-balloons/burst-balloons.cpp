class Solution 
{
    public:
    int maxCoins(vector<int>& a) 
    {
        a.insert(a.begin(),1);
        a.insert(a.end(),1);
        vector<vector<int>> memo(a.size(),vector<int>(a.size(),0));
        return dp(memo,a,1,a.size()-2);
    }
    int dp(vector<vector<int>>&memo,vector<int> &a,int left,int right)
    {
        if(right-left<0)
            return 0;
        if(memo[left][right]>0)
            return memo[left][right];
        int sum=0;
        for(int i=left;i<=right;i++)
        {
            int gain=a[left-1]*a[i]*a[right+1];
            int remaining=dp(memo,a,left,i-1)+dp(memo,a,i+1,right);
            sum=max(sum,remaining+gain);
        }
        memo[left][right]=sum;
        return sum;
    }
};