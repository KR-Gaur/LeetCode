class Solution {
public:
    long long numberOfWays(string s) {
        long len = s.size();
        vector<int> z(len);
        vector<int> o(len);
        if(s[0] == '1'){
            z[0] = 0;
            o[0] = 1;
        }
        else{
            z[0] = 1;
            o[0] = 0;
        }
        
        for(long i=1; i<len; i++){
            if(s[i] == '1'){
                z[i] = z[i-1];
                o[i] = o[i-1]+1; 
            }
            else {
                z[i] = z[i-1]+1;
                o[i] = o[i-1];
            }
        }
        long ans = 0;
        for(long i=0; i<len; i++){
            if(s[i]=='1'){
               ans += z[i]*(z[len-1]-z[i]);
            }
            else{
               ans += o[i]*(o[len-1]-o[i]);
            }
        }
        return ans;
    }
};