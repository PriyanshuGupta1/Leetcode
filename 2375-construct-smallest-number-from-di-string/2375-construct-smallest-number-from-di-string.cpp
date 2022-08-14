class Solution {
public:
    bool recursion(int index,string &t,map <int,int>mp,string pattern,string &res)
    {
        if(index == pattern.size())
        {
            if(res.size() == 0)
                res=t;
            if(t < res)
                res=t;
            return true;
        }
        if(t.size() >pattern.size()+1)
            return false;
        if(pattern[index] == 'I')
        {
            for(int i=1;i<10;i++)
            {
                if(mp[i]==0 && t[index]-'0' < i)
                {
                    mp[i]=1;
                    t+=to_string(i);
                    if(recursion(index+1,t,mp, pattern,res))
                        return true;
                    t.pop_back();
                    mp[i]=0;
                }
            }
        }
        else if(pattern[index] =='D' )
        {
            for(int i=10;i>=1;i--)
            {
                if(mp[i]==0 && t[index]-'0' > int(i))
                {
                    mp[i]=1;
                    t+=to_string(i);
                    if(recursion(index+1, t,mp, pattern,res))
                        return true;
                    t.pop_back();
                    mp[i]=0;
                }
            }
        }
        return false;
    }
    string smallestNumber(string pattern) {
        string t="",res="";
        map <int,int> mp;
        for(int i=1;i<10;i++)
        {
            t+=to_string(i);
            mp[i]=1;
            if(recursion(0,t,mp,pattern,res))
                return res;
            t.pop_back();
            mp[i]=0;
        }
        return res;
    }
};