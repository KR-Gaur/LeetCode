class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int len = s.size();
        int ans = 0;
        int i = 0, j = 0;
        while(j<len){
            if(m.find(s[j])==m.end()){
                m[s[j]]=j;
            }
            else{
               if(m[s[j]]>=i){
                 ans = max(ans, j-i);
                  // cout << i << " " << j << " " << ans << endl;
                 i = m[s[j]]+1;
               }
                m[s[j]]=j;
            }
            j++;
        }    
        return max(ans, j-i);
    }
};