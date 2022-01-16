class Solution {
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        vector <string> w;
        int i,y;
        for(i=0;i<s.length() && i+k<s.length();i+=k)
        {
            string q;
            for(int j=i;j<s.length() && j<i+k;j++)
            {
                q+=s[j];
            }
            w.push_back(q);
        }
        string e;
        y=i;
        for(;i<y+k;i++)
        {
        
            if(i<s.length())
                e+=s[i];
            else
                e+=fill;
            cout<<e<<" ";
        }
        
        w.push_back(e);
        return w;
    }
};