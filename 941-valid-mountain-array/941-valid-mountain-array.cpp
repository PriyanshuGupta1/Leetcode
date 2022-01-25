class Solution
{
public:
    bool validMountainArray(vector<int>& arr) 
    {
        int i;
        if(arr.size()<=2)//the size of the mountain should be atleast 3 i.e 3 elements in array
            return false;
        for(i=1;i<arr.size();i++)    
        {
            if(arr[i]==arr[i-1])// we encountered a plateau
                return false;
            else if(i==1 && arr[i]<arr[i-1])// decreasing size without any peak
                return false;
            else if(arr[i]<arr[i-1])//mountain dip is found
                break;
        }
        if(i==arr.size())//didnt find a peak element
            return false;
        for(;i<arr.size();i++)
        {
            if(arr[i]>=arr[i-1])// second peak found
                return false;
        }
        return true;
    }
};