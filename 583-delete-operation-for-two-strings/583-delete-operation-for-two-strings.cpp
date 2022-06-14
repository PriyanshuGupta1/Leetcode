class Solution {
public:
    int minDistance(string word1, string word2) {
        vector <int> prev(word2.size()+1,0),cur(word2.size()+1,0);
        for(int i=1;i<=word1.size();i++)
        {
            for(int j=1;j<=word2.size();j++)
            {
                if(word1[i-1]==word2[j-1])
                    cur[j]=1+prev[j-1];
                else
                    cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return word1.size()+word2.size()-2*cur[word2.size()];
    }
};