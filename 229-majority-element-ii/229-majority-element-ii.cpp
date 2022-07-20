class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector <int> res;
        int count1=0,count2=0,majEle1=INT_MAX,majEle2=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(count1 == 0 && majEle2 !=nums[i])
            {
                majEle1=nums[i];
                count1++;
                continue;
            }
            if(count2 == 0 && majEle1!=nums[i])
            {
                majEle2=nums[i];
                count2++;
                continue;
            }
            if(majEle1!=nums[i] && majEle2!=nums[i])
            {
                count1--;
                count2--;
            }
            else if(majEle1==nums[i])
                count1++;
            else if(majEle2==nums[i])
                count2++;
        }
        count1=0,count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==majEle1)
                count1++;
            if(nums[i]==majEle2)
                count2++;
        }
        if(count1>nums.size()/3)
            res.push_back(majEle1);
        if(count2>nums.size()/3)
            res.push_back(majEle2);
        return res;
    }
};