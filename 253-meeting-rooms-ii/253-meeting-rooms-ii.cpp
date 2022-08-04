class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int maxi=0;
        for(int i=0;i<intervals.size();i++)
            maxi=max(maxi,intervals[i][1]);
        vector <int> room(maxi+2,0);
        for(int i=0;i<intervals.size();i++)
        {
            room[intervals[i][0]]++;
            room[intervals[i][1]] --;
        }
        int maxRoom=0,sum=0;
        for(int i=0;i<room.size();i++)
        {
            sum+=room[i];
            maxRoom=max(sum,maxRoom);
        }
        return maxRoom;
    }
};