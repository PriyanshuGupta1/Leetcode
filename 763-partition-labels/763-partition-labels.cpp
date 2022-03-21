class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector <int> a;
        if(s.length()==0)
            return a;
        map <int,int> foccur,loccur;
        for(int i=0;i<s.length();i++)
        {
            if(foccur[s[i]-'a']==0)
            {
                foccur[s[i]-'a']=i+1;
                loccur[s[i]-'a']=i+1;
            }
            else
                loccur[s[i]-'a']=i+1;
        }
        int last=-1,first=0;
        for(int i=0;i<s.length();i++)
        {
            if(last==-1)
            {
                first=foccur[s[i]-'a']-1;
                last=loccur[s[i]-'a']-1;
            }
            if(last==i)
            {
                a.push_back(last-first+1);
                last=-1;
            }
            else
            {
                if(last>=loccur[s[i]-'a']-1)
                    continue;
                else
                    last=loccur[s[i]-'a']-1;
            }
        }
        return a;
    }
};