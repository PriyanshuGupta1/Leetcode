class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) 
    {
        int count_0=0,count_1=0,x,y=0;
        vector <int> a;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                count_1++;
        }
        x=count_1;
        int max_score=count_1;
        for(int i=0;i<nums.size();i++)
        {
            int curr_score=0;
            if(nums[i]==0)   
                count_0++;
            else
                count_1--;
            curr_score=count_0+count_1;
            max_score=max(curr_score,max_score);
        }
        cout<<max_score<<" ";
        count_0=0;
        count_1=x;
        if(max_score==count_1)
            a.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            int curr_score=0;
            if(nums[i]==0)   
                count_0++;
            else
                count_1--;
            curr_score=count_0+count_1;
            if(curr_score==max_score)
                a.push_back(i+1);
        }
        return a;
    }
};