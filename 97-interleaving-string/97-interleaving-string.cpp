class Solution {
public:
    bool recursion(int index1,int index2,int index3,string &s1,string &s2,string &s3,vector <vector <int>> &dp)
    {
        // base condition ,stoppage condition for recursion
        // s3 is completely traversed
        if(index3==s3.size() && index2==s2.size() && index1==s1.size())
            return true;
        if(dp[index1][index2] != -1)
            return dp[index1][index2];
        // s1[index1] matches with s3
        bool res=false;
        if(s1[index1]==s3[index3])
        {
            if(recursion(index1+1,index2,index3+1,s1,s2,s3,dp))
                res=true;
        }
        // s2[index2] matches with s3
        if(s2[index2]==s3[index3])
        {
            if(recursion(index1,index2+1,index3+1,s1,s2,s3,dp))
                res=true;
        }
        return dp[index1][index2]=res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        // we can solve this ques using recursion 
        // best case time complexity : O(s3.length()) all char are diff of s1,s2 and s3
        // worst case time complexity : O(2^(s1.length()+s2.length())) all char of s1 s2 and s3 are same
        // Space complexity :O(s1.size()+s2.size())
        if(s1.size()+s2.size() != s3.size())
            return false;
        vector <vector <int>> dp(s1.size()+1,vector <int>(s2.size()+1,-1));
        return recursion(0,0,0,s1,s2,s3,dp);
    }
};