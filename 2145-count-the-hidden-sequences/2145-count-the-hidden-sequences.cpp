class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) 
    {
        vector <long long> hidden(differences.size()+1);
        hidden[0]=lower;
        for(long long i=1;i<=differences.size();i++)
        {
            hidden[i]=hidden[i-1]+differences[i-1];
        }
        int low=INT_MAX,high=INT_MIN;
        cout<<endl;
        for(int i=0;i<hidden.size();i++)
        {
            if(hidden[i]<low)
                low=hidden[i];
            if(hidden[i]>high)
                high=hidden[i];
        }
        cout<<low<<" "<<high;
        if(upper<high && lower>low)
        {
            cout<<"Aa";
            return 0;
        }
        else if(low>lower && high<upper)
        {
            int sum=min((upper-high),(lower-low));
            cout<<sum<<" vd"<<sum;
            if(sum<0)
                return 0;
            return sum;
        }
        else if(high>=upper && lower>=low && high!=lower)
        {
            lower-=high-upper;
            cout<<"A";
            if((lower-low)<0)
                return 0;
            return (lower-low+1);
        }
        else if(low<=lower && high<=upper)
        {
            cout<<"B";
            high+=lower-low;
            if((upper-high)<0)
                return 0;
            return (upper-high+1);
        }
        else if(high>upper && low<lower)
        {cout<<"C";
            return 0;
        }
        return 0;
    }
};