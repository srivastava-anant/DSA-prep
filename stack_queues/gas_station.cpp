class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int total = 0;   // overall fuel balance (can a tour exist?)
        int tank  = 0;   // fuel in tank while scanning
        int start = 0;   // candidate starting station

        for (int i = 0; i < gas.size(); i++) {

            int gain = gas[i] - cost[i];
            total += gain;
            tank  += gain;

            // If we can't reach i+1 from current start,
            // none of the stations from start..i can be valid.
            if (tank < 0) {
                start = i + 1;  // next station becomes new candidate
                tank = 0;       // reset tank for the new start
            }
        }

        // If total gas < total cost, no solution exists
        return (total >= 0) ? start : -1;
    }
};
