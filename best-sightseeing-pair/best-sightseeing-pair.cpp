class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int len = values.size(); 
        int ans = values[0];
        int vi_max = values[0]+0;
        for( int j=1; j<len; j++ ){
            ans = max(ans, vi_max + values[j]-j);
            vi_max = max(vi_max, values[j]+j);
        }
        
        return ans;
    }
};