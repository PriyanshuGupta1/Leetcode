class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector <vector <int>> res;
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it: intervals)
            pq.push({it[0],it[1]});
        // cout<<pq.size();
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            if( !pq.empty() )
            {
                auto top2=pq.top();
                int top1In=top2.first,top1Out=top2.second;
                if(top.first<=top1In && top1In<=top.second)
                {
                    pq.pop();
                    pq.push({top.first,max(top.second,top1Out)});
                }
                else
                {
                    vector <int> curr;
                    curr.push_back(top.first);
                    curr.push_back(top.second);
                    res.push_back(curr);
                }
            }
            else
            {
                vector <int> curr;
                curr.push_back(top.first);
                curr.push_back(top.second);
                res.push_back(curr);
            }
        }
        return res;
    }
};