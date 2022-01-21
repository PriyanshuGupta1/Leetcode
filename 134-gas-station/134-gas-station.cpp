class Solution {
  public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    int total_tank = 0;
    int curr_tank = 0;
    int starting_station = 0;
    for (int i = 0; i < n; ++i) {
      total_tank += gas[i] - cost[i];
      curr_tank += gas[i] - cost[i];
      if (curr_tank < 0) {
        starting_station = i + 1;
        curr_tank = 0;
      }
    }
    return total_tank >= 0 ? starting_station : -1;
  }
};