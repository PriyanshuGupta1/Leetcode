class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector <int> v;
        int left=0,right=numbers.size()-1;
        while(left<right)
        {
            int curr_sum=numbers[left]+numbers[right];
            if(curr_sum==target)
            {
                v.push_back(left+1);
                v.push_back(right+1);
                return v;
            }
            else if(curr_sum>target)
                right--;
            else
                left++;
            
        }
        return v;
    }
};