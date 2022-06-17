class Solution {
public:
    int numSplits(string s) {
        map <int,int> lmap,rmap;
        for(int i=0;i<s.length();i++)
            rmap[s[i]]++;
        int count=0;
        int leftDistinct=0,rightDistinct=0;
        for(auto it=rmap.begin();it!=rmap.end();it++)
            rightDistinct++;
        for(int i=0;i<s.length();i++)
        {
            if(lmap[s[i]]==0)
                leftDistinct++;
            lmap[s[i]]++;
            rmap[s[i]]--;
            if(rmap[s[i]]==0)
                rightDistinct--;
            if(leftDistinct==rightDistinct)
                count++;
        }
        return count;
    }
};