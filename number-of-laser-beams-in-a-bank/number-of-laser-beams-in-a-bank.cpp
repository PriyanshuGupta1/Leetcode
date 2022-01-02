class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int final_ans=0,prev_level=0;
        for(int i=0;i<bank.size();i++)
        {
            string s=bank[i];
            int curr_level=0;
            for(int j=0;j<s.length();j++)
            {
                if(s[j]=='1')
                    curr_level++;
            }
            if(curr_level*prev_level>0)
                final_ans+=curr_level*prev_level;
            if(curr_level!=0)
                prev_level=curr_level;
        }
        return final_ans;
    }
};