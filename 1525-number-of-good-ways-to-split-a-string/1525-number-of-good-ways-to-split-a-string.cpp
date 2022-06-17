class Solution {
public:
    int numSplits(string s) {
        unordered_map <int,int> lmap,rmap;
        for(int i=0;i<s.length();i++)
            rmap[s[i]]++;
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            int leftDistinct=0,rightDistinct=0;
            lmap[s[i]]++;
            rmap[s[i]]--;
            for(auto it=lmap.begin();it!=lmap.end();it++)
            {
                if(it->second != 0)
                    leftDistinct++;
            }
            for(auto it=rmap.begin();it!=rmap.end();it++)
            {
                if(it->second != 0)
                rightDistinct++;
            }
            // cout<<leftDistinct<<" "<<rightDistinct<<endl;
            if(leftDistinct==rightDistinct)
                count++;
        }
        return count;
    }
};