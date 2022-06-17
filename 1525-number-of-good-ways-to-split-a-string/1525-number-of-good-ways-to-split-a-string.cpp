class Solution {
public:
    int numSplits(string s) {
        vector <int> lmap(26,0),rmap(26,0);
        for(int i=0;i<s.length();i++)
            rmap[s[i]-'a']+=1;
        int count=0;
        int leftDistinct=0,rightDistinct=0;
        for(auto it=rmap.begin();it!=rmap.end();it++)
        {
            if(*it!=0)
            rightDistinct++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(lmap[s[i]-'a']==0)
                leftDistinct++;
            lmap[s[i]-'a']++;
            rmap[s[i]-'a']--;
            if(rmap[s[i]-'a']==0)
                rightDistinct--;
            if(leftDistinct==rightDistinct)
                count++;
        }
        return count;
    }
};