class Solution {
    
public:
    
    void display(int sLen, int pLen, vector< vector<bool> > &dp ){
    cout<< endl;
    
      for( int i=0; i<sLen+1; i++ ){
        for( int j=0; j<pLen+1; j++)
            cout << dp[i][j]<<" ";
        cout<< endl;
    }
    cout << endl;
}
    
    bool isMatch(string s, string p) {
          int sLen = s.size();
    int pLen = p.size();
	vector< vector<bool> > dp(sLen+1, vector<bool>(pLen+1));
    
    dp[0][0] = true;
        
    for( int j=1; j<pLen+1; j++){
        if( p[j-1] == '*' )
            dp[0][j] = dp[0][j-2]; 
        else
            dp[0][j] =false; 
        
    }
    for( int i=1; i<sLen+1; i++){
        dp[i][0] = false;
    }
        
    
  
    for( int i=1; i<sLen+1; i++ ){
        for( int j=1; j<pLen+1; j++){
            if( p[j-1] == s[i-1] || p[j-1] == '.' )
                dp[i][j] = dp[i-1][j-1];
            
            else if(p[j-1] == '*'){
                dp[i][j] = dp[i][j-2];
                if(s[i-1] == p[j-2] || p[j-2] == '.'){
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
            else 
             dp[i][j] = false;   
        }
        
        // display(sLen, pLen, dp);
    }
    return dp[sLen][pLen];        
    }
};