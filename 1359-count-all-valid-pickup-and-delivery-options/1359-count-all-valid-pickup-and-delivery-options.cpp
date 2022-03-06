class Solution {
private:
    int MOD = 1e9 + 7;
    vector<vector<int>> memo;
    
    long totalWays(int unpicked, int undelivered) {
        if (unpicked == 0 && undelivered == 0) 
            return 1;
        if (unpicked < 0 || undelivered < 0 || undelivered < unpicked) 
            return 0;
        
        if (memo[unpicked][undelivered]) 
                return memo[unpicked][undelivered];
        long ans = 0;
        ans += unpicked * totalWays(unpicked - 1, undelivered);
        ans %= MOD;
        ans += (undelivered - unpicked) * totalWays(unpicked, undelivered - 1);
        ans %= MOD;
        return memo[unpicked][undelivered] = ans;
    }
public:
    int countOrders(int n) {
        memo = vector<vector<int>> (n + 1, vector<int>(n + 1, 0));
        return totalWays(n, n);
    }
};