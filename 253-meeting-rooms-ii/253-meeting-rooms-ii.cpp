class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // Naive approach
        // int maxi=0;
        // for(int i=0;i<intervals.size();i++)
        //     maxi=max(maxi,intervals[i][1]);
        // vector <int> room(maxi+2,0);
        // for(int i=0;i<intervals.size();i++)
        // {
        //     room[intervals[i][0]]++;
        //     room[intervals[i][1]] --;
        // }
        // int maxRoom=0,sum=0;
        // for(int i=0;i<room.size();i++)
        // {
        //     sum+=room[i];
        //     maxRoom=max(sum,maxRoom);
        // }
        // return maxRoom;
        vector <int> arrival;
        vector <int> dept;
        for(int i=0;i<intervals.size();i++)
        {
            arrival.push_back(intervals[i][0]);
            dept.push_back(intervals[i][1]);
        }
        sort(arrival.begin(),arrival.end());
        sort(dept.begin(),dept.end());
        int i=0,j=0,plat=0,count=0;
        while( i < intervals.size() )
        {
            while( dept[j] <= arrival[i] )
            {
                j++;
                plat--;
            }
            i++;
            plat++;
            count=max(count,plat);
        }
        return count;
    }
};