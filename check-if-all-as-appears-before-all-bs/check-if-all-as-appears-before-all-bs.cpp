class Solution {
public:
    bool checkString(string s) 
    {
        int last_index_a=-1,last_index_b=-1;
        for(int i=0;i<s.length();i++)
        {
            if(last_index_b<last_index_a && last_index_b!=-1)
                return false;
            if(s[i]=='a')
                last_index_a=i;
            if(s[i]=='b')
                last_index_b=i;
        }
        if(last_index_b<last_index_a && last_index_b!=-1)
                return false;
        return true;
        
    }
};