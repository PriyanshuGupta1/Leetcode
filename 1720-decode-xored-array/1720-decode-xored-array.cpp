class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) 
    {
        vector <int> a;
        a.push_back(first);
        for(int i=0;i<encoded.size();i++)
        {
            first=encoded[i]^a[i];
            a.push_back(first);
        }
        return a;
    }
};