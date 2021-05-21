class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        vector<char> map(26,-1);
        vector<char> available(26,1);
        int n = words.size();
        for( int j=0; j<n; j++ ){
            if( words[j].size() != pattern.size() ) continue;
            int i=0;
            for( ;i<words[j].size(); i++ ){
                   if(map[pattern[i]-'a'] == -1 && available[words[j][i]-'a']){
                       map[pattern[i]-'a'] = words[j][i];
                       available[words[j][i]-'a'] = 0;
                   }
                   else if( map[pattern[i]-'a'] == words[j][i] ) continue;
                   else break;
            }
            // cout<<words[j]<< " "<< i<< endl;
            if( i==words[j].size() ) ans.push_back(words[j]);
            for( int i=0; i<26; i++){
                map[i] = -1;
                available[i] = 1;
            }
         }
        return ans;
    }
};