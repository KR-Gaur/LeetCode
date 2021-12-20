class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = -5000000;
        int curMin = 5000000;
        int len = nums.size();
        int maxi = -5000000;
        int mini = 5000000;
        int sum = 0;
        for( int i=0; i<len; i++ ){
            curMax = max(nums[i], nums[i]+curMax);
            maxi = max(curMax, maxi);
            
            curMin = min(nums[i], nums[i]+curMin);
            mini = min(curMin, mini);
            
            sum+=nums[i];
        }
        
        if( sum == mini )
            return maxi;
        return max(maxi, sum-mini);
    }
};