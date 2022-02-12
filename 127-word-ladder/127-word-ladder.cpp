class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> wordSet;
        bool isPresent = false;
        for(string word: wordList)
        {
            if(endWord.compare(word)==0)
                isPresent=true;        
            wordSet.insert(word);
        }
        if(isPresent==false)
            return 0;
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        while(q.empty()==false)
        {
            depth=depth+1;
            int levelSize=q.size();
            while(levelSize--)
            {
                string curr=q.front();
                q.pop();
                for(int i=0;i<curr.length();++i)
                {
                    string temp=curr; 
                    for(char c='a';c<='z';++c)
                    {
                        temp[i]=c;
                        if(curr.compare(temp)==0)
                            continue;
                        if(temp.compare(endWord)==0)
                            return depth + 1;
                        if(wordSet.find(temp)!=wordSet.end())
                        {
                            q.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};