class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) 
    {
        vector <long long > v;
        if(finalSum%2==1)    
            return v;
        long long n=1;
        for(long long i=1;i<finalSum;i++)
        {
            n=i*(i+1);
            v.push_back(2*i);
            if(n>=finalSum)
            {
                cout<<finalSum-n<<" ";
                v.erase(remove(v.begin(), v.end(), n-finalSum), v.end());
                break;
            }
        }
        return v;
    }
};
