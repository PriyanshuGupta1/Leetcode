class Solution {
public:
     int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m; //<c, i>
        int n=nums.size();
        int c=0, ans=0;
        for(int i=0; i<n; i++){
            c += (nums[i]==1)? 1: -1;
            if(c==0)
                ans = max(ans, i+1); 
            if(m.count(c))
                ans = max(ans, i - m[c]);
            else
                m[c] = i; 
        }
        return ans;
    }
};