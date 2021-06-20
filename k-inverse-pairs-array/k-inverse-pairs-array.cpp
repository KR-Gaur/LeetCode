class Solution {
public:
    int kInversePairs(int n, int k) {
        
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        
        for(int i=0; i<k+1; i++)
            dp[0][i] = 0;
        
        for(int i=0; i<n+1; i++)
            dp[i][0] = 1;    

        for(int i=1; i<n+1; i++){
            for(int j=1; j<k+1; j++){
                // for( int p=0; p<=min(j, i-1); p++ ){
                //     dp[i][j] = ( dp[i][j] + dp[i-1][j-p] ) % (1000000007);                    
                // }
                int v = ( dp[i-1][j] + 1000000007 - ( (j-i) >= 0 ? dp[i-1][j-i] : 0) )% 1000000007;
                dp[i][j] = ( dp[i][j-1] + v ) % (1000000007);
            }
        }
        
        return dp[n][k];
        
    }
};