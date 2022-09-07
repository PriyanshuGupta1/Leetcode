class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map <string,int> umap;
        int right=0;
        vector <string> res;
        string t;
        while(right < s.length())
        {
            if(right < 10 )
                t+=s[right];
            else
            {
                umap[t]++;
                string r=t.substr(1,9)+s[right];
                t=r;
            }
            right++;
        }
        umap[t]++;
        for(auto it=umap.begin();it!=umap.end();it++)
        {
            if(it->second > 1)
                res.push_back(it->first);
        }
        return res;
    }
};