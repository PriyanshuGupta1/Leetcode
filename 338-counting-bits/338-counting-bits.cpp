class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector <int > v(n+1);
        v[0]=0;
        for(int i=0;i<=n;i++)
        {
            v[i]=v[i/2]+i%2;
        }
        return v;
    }
};
// vector<int> countBits(int n) 
//     {
//         vector <int > v;
//         for(int i=0;i<=n;i++)
//         {
//             int num=i,count=0;
//             while(num>0)
//             {
//                 if(num&1)
//                     count++;
//                 num>>=1;
//             }
//             v.push_back(count);
//         }
//         return v;
//     }