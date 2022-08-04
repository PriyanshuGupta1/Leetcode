class Solution {
public:
    // static 
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue <int,vector <int>,greater <int>> pq;
        pq.push(intervals[0][1]);
        int maxSize=1;
        for(int i=1;i<intervals.size();i++)
        {
            auto top=pq.top();
            if(top <= intervals[i][0])
            {
                pq.pop();
                pq.push(intervals[i][1]);
            }
            else
            {
                pq.push(intervals[i][1]);
            }
            int size=pq.size();
            maxSize=max(maxSize,size);
        }
        return maxSize;
    }
};