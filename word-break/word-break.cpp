class Solution {
public:
    bool rec(string s, int start, vector<string>& wordDict){
        int len = s.size();
        if(start >= len)
            return true;
        
        string ans="";
        for(int i=start; i<len; i++){
            ans+=s[i];
            if(find(wordDict.begin(), wordDict.end(), ans) != wordDict.end() 
               && rec(s, i+1, wordDict))
                return true;
        }
        
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // TLE
        // return rec(s, 0, 0, wordDict);
        int len = s.size();
        vector<bool> dp(len+1, false);
        dp[0] = true;
        for( int i=0; i<len; i++ ){
            if(dp[i]){
                for(string word : wordDict){
                    if(i+word.size()-1 < len && word == string_view(&s[i], word.size()))
                        dp[i+word.size()] = true;
                }
            }
        }
        for( int i=0; i<len+1; i++ )
            cout<<dp[i]<<" ";
        return dp[len];
    }
};