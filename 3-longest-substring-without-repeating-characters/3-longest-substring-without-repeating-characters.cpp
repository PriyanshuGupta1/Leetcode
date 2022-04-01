class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.length()==0)
            return 0;
        int count=0,left=0;
        for(int i=0;i<s.length();i++)
        {
            int curr_count=1;
            for(int j=i-1;j>=left;j--)
            {
                if(s[i]!=s[j])
                    curr_count++;
                else
                {
                    count=max(count,curr_count);
                    left=j+1;
                }
            }
            count=max(count,curr_count);
        }
        return count;
    }
};