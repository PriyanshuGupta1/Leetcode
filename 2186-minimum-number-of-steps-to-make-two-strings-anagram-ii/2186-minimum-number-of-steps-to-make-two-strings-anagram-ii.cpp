class Solution {
public:
    int minSteps(string s, string t) 
    {
        int count=0;
        vector <int> a (26,0);
        for(int i=0; i<s.length(); i++)
        {
            a[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++)
        {
            a[t[i]-'a']--;
        }
        for(int i=0; i<26; i++)
        {
            if(a[i]!=0)
              count+=abs(a[i]);
        }
        return count;
    }
};
