class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x=m-1,y=n-1;
        for(int i=m+n-1;i>=0;i--)
        {
            if(x<0 || (y>=0 && nums1[x]<nums2[y]))
                nums1[i]=nums2[y--];
            else
                nums1[i]=nums1[x--];
        }

    }
};