class Solution {
public:
    int minimumSum(int num) 
    {
        vector <int> a;
        while(num>0)
        {
            a.push_back(num%10);
            num/=10;
        }
        for(auto x:a)
            cout<<x<<" ";
        sort(a.begin(),a.end());
        int new1=0,new2=0;
        new1=a[0]*10+a[2];
        new2=a[1]*10+a[3];
        return new1+new2;
    }
};