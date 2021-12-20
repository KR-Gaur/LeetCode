class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if( nums.size() == 1 ) return k==nums[0];
        int len = nums.size();
        unordered_map< int, vector<int>> m;
        int pSum=0;
        int ans = 0;
        m[0].push_back(-1);
        for(int i=0; i<len; i++){
            pSum+=nums[i];
            if(m.find(pSum-k) != m.end()){
                ans+=m[pSum-k].size();
            }
            m[pSum].push_back(i);
        }
        return ans;
        
    }
};