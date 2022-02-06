class Solution {
public:
    int removeDuplicates(vector<int>& a) 
    {
        if(a.size()==0)
            return 0;
        int prev=a[0];
        for(int i=1;i<a.size();i++)
        {
            if(a[i]==prev)
            {
                a.erase(a.begin()+i);    
                i--;
            }
            prev=a[i];
        }
        return a.size();
    }
};