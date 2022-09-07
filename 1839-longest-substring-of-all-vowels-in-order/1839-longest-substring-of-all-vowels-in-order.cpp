class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector <char> vec(5,'a');
        vec[0]='a';
        vec[1]='e';
        vec[2]='i';
        vec[3]='o';
        vec[4]='u';        
        int first=0,last=0,maxLen=0,currPosn=0;
        while(last<word.size())
        {
            // first can only be starting from a
            // so if first==last
            // lets check if it starts with a
            if(first == last)
            {
                if(word[first] == 'a')
                    last++;
                else
                    first++,last++;
            }
            else
            {
                
                if(word[last]==vec[currPosn])
                    last++;
                else if(currPosn!=4 && word[last]==vec[currPosn+1])
                    currPosn++,last++;
                else
                    first=last,currPosn=0;
                if(currPosn == 4)
                    maxLen=max(maxLen,last-first);
            }
        }
        return maxLen;
    }
};