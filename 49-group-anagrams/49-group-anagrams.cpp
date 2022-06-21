class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map <string,vector <string>> map;
        for(int i=0;i<strs.size();i++)
        {
            string t=strs[i];
            sort(t.begin(),t.end());
            map[t].push_back(strs[i]);
        }
        for(auto it=map.begin();it!=map.end();it++)
            res.push_back(it->second);
        return res;
    }
};