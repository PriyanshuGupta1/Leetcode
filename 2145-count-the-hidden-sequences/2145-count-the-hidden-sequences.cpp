class Solution {
public:
    int numberOfArrays(vector<int>& A, int lower, int upper) {
        long sum = 0, mn = 0, mx = 0;
        for (int n : A) {
            sum += n;
            mn = min(mn, sum);
            mx = max(mx, sum);
        }
        return max(0L, mn - mx + upper - lower + 1);
    }
};