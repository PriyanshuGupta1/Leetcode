class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        vector <int > a,b;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==key)
            {
                int flag=1;
                for(int i=0;i<nums.size();i++)
                {
                    if(abs(i-j)<=k)
                    {
                        a.push_back(i);
                        flag=0;
                    }
                    else if(flag==0)
                        continue;
                         
                }
            }
        }
        sort(a.begin(),a.end());
        if(a.size()==1)
            return a;
        for(int i=0;i<a.size()-1;i++)
        {
            if(a[i]!=a[i+1])
                b.push_back(a[i]);
        }
        b.push_back(a[a.size()-1]);
        return b;
    }
};