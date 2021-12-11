class Solution {
public:
    int integerBreak(int n) {
        vector<int> a(60,0);
        a[1] = 1;
        for( int i=2; i<=n; i++ ){
            int maximumOfAllPossiblePairs = 0;
            for(int number = 1; number<=i/2; number++){
                int left = max(number,a[number]);
                int right = max(i-number, a[i-number]);
                maximumOfAllPossiblePairs = max(left*right, maximumOfAllPossiblePairs);
            }
            a[i] = maximumOfAllPossiblePairs;
        }
        return a[n];
    }
};