class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        vector<int> lengthOfTrip = vector<int>(1001);
        for (auto t : trips)
        {
            lengthOfTrip[t[1]] += t[0];
            lengthOfTrip[t[2]] -= t[0];
        }
        int carLoad = 0;
        for (int i = 0; i < 1001 && carLoad <= capacity; i++)
        {
            carLoad += lengthOfTrip[i];
            if(carLoad > capacity) 
                return false;
        }
        return true;
    }
};