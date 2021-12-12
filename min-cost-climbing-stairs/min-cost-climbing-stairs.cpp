class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev_1 = cost[0];
        int prev_2 = cost[1];
        int len = cost.size();
        int t = INT_MAX;
        for( int i=2; i<len; i++ ){
            t = min(prev_1, prev_2) + cost[i];
            prev_1 = prev_2;
            prev_2 = t;
        }
        return min(prev_1, prev_2);
    }
};