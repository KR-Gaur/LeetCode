#include<string>

class Solution {
public:
    
    string getHint(string secret, string guess) {
        
        unordered_map<int, vector<int>> m;
        vector<int> v(1001, 0);
        int len = secret.size();
        int bull=0, cow=0;

        for(int i=0; i<len; i++){
            if(secret[i] == guess[i]){
                bull++;
                v[i]=1;
            }
            else 
                m[secret[i]].push_back(i);
            
        }
        
        for(int i=0; i<len; i++){
            if( !v[i] && m.find(guess[i]) != m.end() && m[guess[i]].size() > 0){
                m[guess[i]].pop_back();
                cow++;
            }
            
        }
        string ans = "";
        ans += to_string(bull)+'A'+to_string(cow)+'B';
        return ans;
    }
};