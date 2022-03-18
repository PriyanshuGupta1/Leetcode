class Solution {
public:
    int search(vector<int>& arr,int target){
        int n=arr.size();
        int start=0, end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>=arr[start]){
                if(target<=arr[mid] &&target>=arr[start]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(target<=arr[end] && target>=arr[mid]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};