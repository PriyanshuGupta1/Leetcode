class Solution {
public:
    bool isHappy(int n) {
        if(n==1)
            return true;
        int curr=n,prev=1;
        map <long long ,long long> mp;
        while(n!=1)
        {
            mp[curr]=1;
            if(prev==curr)
                break;
            prev=curr;
            int num=curr,sum=0;
            while(num>0)
            {
                int dig=num%10;
                sum+=dig*dig;
                num/=10;
            }
            
            curr=sum;
            if(mp[curr])
                break;
        }
        return curr==1 ? true :false;
    }
};