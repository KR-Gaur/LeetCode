class Solution {
public:
    int tribonacci(int n) {
        
        long t0 = 0;
        long t1 = 1;
        long t2 = 1;
        
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        long tn;
        for( int i=3; i<=n; i++ ){
            tn = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = tn;
        }
        return tn;        
    }
};