class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // brute force approach
        // form a dual array sort it
        vector <int> curr;
        for(int i=0;i<nums1.size();i++)
            curr.push_back(nums1[i]);
        for(int i=0;i<nums2.size();i++)
            curr.push_back(nums2[i]);
        sort(curr.begin(),curr.end());
        if(curr.size()%2 != 0)
            return curr[(curr.size()-1)/2];
        else
            return (double) (curr[curr.size()/2]+curr[curr.size()/2-1])/2;
        
    }
};