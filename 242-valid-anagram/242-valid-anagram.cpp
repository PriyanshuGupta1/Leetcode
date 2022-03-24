class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        vector <int> seq(26,0);
        for(int i=0;i<s.length();i++)
            seq[s[i]-'a']++;
        for(int i=0;i<t.length();i++)
            seq[t[i]-'a']--;
        for(int i=0;i<seq.size();i++)
            if(seq[i]!=0)
                return false;
        return true;
    }
};