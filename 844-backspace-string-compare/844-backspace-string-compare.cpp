class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        string a,b;
        for(int i=0;i<s.length();i++)
        {
            if(a.length()!=0 && s[i]=='#')
                a.erase(a.length()-1,a.length());
            else if(s[i]!='#')
                a+=s[i];
        }
        for(int i=0;i<t.length();i++)
        {
            if(b.length()!=0 && t[i]=='#')
                b.erase(b.length()-1,b.length());
            else if(t[i]!='#')
                b+=t[i];
        }
        // cout<<a<<" "<<b;
        if(!a.compare(b))
            return true;
        else 
            return false;
    }
};