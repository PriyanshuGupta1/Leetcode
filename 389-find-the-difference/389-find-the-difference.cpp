class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        int sum1=0,sum2=0;
        for(int i=0;i<s.length();i++)
            sum1+=s[i]-'a'+1;
        for(int i=0;i<t.length();i++)
            sum2+=t[i]-'a'+1;
        char q=sum2-sum1+'a'-1;
        return q;
    }
};