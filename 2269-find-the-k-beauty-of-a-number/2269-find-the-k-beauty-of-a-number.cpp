class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int count=0;
        string res=to_string(num);
        int last=0;        
        while(last+k<=res.size())
        {
            int t=stoi(res.substr(last,k));
            if(t!=0 && num%t==0)
                count++;
            last++;
        }
        return count;
    }
};