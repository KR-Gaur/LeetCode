class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if( nums.size() == 1 ) return nums[0];
        
        int len = nums.size();
        int maxi = nums[0];
        int curMax = nums[0];
        for( int i=1; i<len; i++ ){
            curMax = max( curMax+nums[i], nums[i] );
            maxi = max( maxi, curMax );
        }
        return maxi;
    }
};