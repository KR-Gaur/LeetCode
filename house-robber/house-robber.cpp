class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> ans(nums.size());
        
        for(int i=0; i<nums.size(); i++){
            
            if(i-2 >=0) { 
                ans[i] = max(ans[i-2] + nums[i], ans[i-1]);
            }
            
            else if(i-1>=0) 
                ans[i] = max(ans[i-1], nums[i]);
            
            else
                ans[i] = nums[i];
        }        
        
        return ans[nums.size()-1];
    }
};