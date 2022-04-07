class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)
            return stones[0];
        while(stones.size()>1)
        {
            sort(stones.begin(),stones.end());   
            int high=stones[stones.size()-1],high2=stones[stones.size()-2];
            stones.erase(stones.begin()+stones.size()-2,stones.end());
            if(high!=high2)
                stones.push_back(high-high2);
        }
        if(stones.size()==0)
            return 0;
        return stones[0];
    }
};