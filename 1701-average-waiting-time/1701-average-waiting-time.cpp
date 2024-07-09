class Solution {
public:
    // 2,6,7 => 15/3.0
    // 2,6,4,1
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time = 0;      // time untill chef is busy
        double waiting = 0; // waiting time

        for (auto detail : customers) {
            int arrival = detail[0];
            int order = detail[1]; // order completion time;
            int wait = max(0, time - arrival) + order;
            time = arrival + wait;
            waiting += wait;
        }

        return waiting / customers.size();
    }
};