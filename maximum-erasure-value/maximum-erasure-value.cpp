class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> m;
        vector<int> prefix(n, 0);
        
        int ans=nums[0];
        m[nums[0]] = 0;
        prefix[0] = nums[0];
        int l=0;
        
        for(int i=1; i<nums.size(); i++){
            
            prefix[i] = nums[i] + prefix[i-1];
                
            if(m.find(nums[i]) == m.end() || m[nums[i]] < l){
                m[nums[i]] = i;
            }
            else{
                ans = max(ans, prefix[i-1] - prefix[l]+ nums[l]);
                int ind=m[nums[i]];
                l = ind+1;
                m[nums[i]]=i;
            }
        }
        return max(ans, nums[l] + prefix[n-1]-prefix[l]);
    }
};