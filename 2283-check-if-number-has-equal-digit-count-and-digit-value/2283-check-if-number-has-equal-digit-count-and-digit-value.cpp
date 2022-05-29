class Solution {
public:
    bool digitCount(string num) {
        map <int,int> mp;
        for(int i=0;i<num.size();i++)
        {
            int t=num[i]-'0';
            mp[t]++;
        }
        for(int i=0;i<num.size();i++)
        {
            cout<<mp[i]<<" "<<i<<endl ;
            if(mp[i]!=num[i]-'0')
                return false;
        }
        return true;
    }
};