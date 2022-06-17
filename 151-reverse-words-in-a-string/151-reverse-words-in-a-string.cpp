class Solution {
public:
    string reverseWords(string s) {
        stringstream t(s);
        string a,res;
        while(t >> a)
            res=a+" "+res;
        res.erase(res.end()-1);
        return res;
    }
};