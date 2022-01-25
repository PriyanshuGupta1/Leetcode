class Solution {
public:
    bool validMountainArray(vector<int>& arr) 
    {
        int i;
        if(arr.size()<=2)
            return false;
        for( i=1;i<arr.size();i++)    
        {
            if(arr[i]==arr[i-1])
                return false;
            if(i==1 && arr[i]<arr[i-1])
                return false;
            if(arr[i]<arr[i-1])
                break;
        }
        if(i==arr.size())
            return false;
        for(;i<arr.size();i++)
        {
            if(arr[i]>=arr[i-1])
                return false;
        }
        return true;
    }
};