class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0;
        int left=0,right=height.size()-1;
        while(left<right)
        {
            max_area=max(min(height[left],height[right])*(right-left),max_area);
            if(height[left]<height[right])
                left++;
            else
                right--;  
        }
        return max_area;
    }
};