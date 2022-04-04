// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    	string previousNumber(string S)
    {
        // code here 
        int ind1 =-1;
        int n = S.size();
        for(int i=n-2;i>=0;i--)
        {
            if(S[i]>S[i+1])
            {
                ind1 = i;
                break;
            }
        }
        if(ind1 ==-1)
            return "-1";
        int ind2  = -1;
        for(int i=ind1+1;i<n;i++)
        {
            if(S[i]<S[ind1])
            {
                if(ind2==-1)
                    ind2 = i;
                else if( S[i]>S[ind2])
                {
                  ind2 = i;
                }
            }
        }
        swap(S[ind1],S[ind2]);
        if(S[0]=='0')
        return "-1";
        return S;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends