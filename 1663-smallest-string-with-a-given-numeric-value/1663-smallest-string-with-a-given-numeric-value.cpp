class Solution {
public:
    string getSmallestString(int n, int k) {
        string t;
        int q=n;
        while(k>0 && q>0)
        {
            if((q-1)*26>=k-1)
            {
                t+='a';
                k--; q--;
            }
            else
            {
                // cout<<(k-(q-1)*26);
                t+=(k-(q-1)*26)+'a'-1;
                k=k-((k-(q-1)*26));
                q--;
            }
        }
        return t;
    }
};