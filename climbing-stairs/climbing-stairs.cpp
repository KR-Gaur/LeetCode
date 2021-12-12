class Solution {
public:
    int climbStairs(int n) {
        // vector<int>a(n+1,0);
        // a[0]=1;
        int prev_1=1;
        // a[1]=1;
        int prev_2=1;
        for( int i=2; i<=n; i++ ){
            int t = prev_1+prev_2;
            prev_2=prev_1;
            prev_1=t;
        }
        return prev_1;
    }
};