class Solution {
public:
	int subarraySum(vector<int>& a, int k) 
    {
		int sum=0,count=0;
		unordered_map<int, int> m;
		m[sum]++;
		for (int i : a) 
        {
			sum+=i;
			if(m.find(sum-k)!=m.end()) 
                count+=m[sum-k];
			m[sum]++;
		}
		return count;
	}
};