class Solution {
public:
    vector<long long> sumOfThree(long long num) 
    {
        vector <long long > v;
        if(num%3!=0)
            return v;
        long long y=num/3;
        v.push_back(y-1);
        v.push_back(y);
        v.push_back(y+1);
        return v;
    }
};