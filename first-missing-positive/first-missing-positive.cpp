class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for( int i=0; i<len; i++ ){
            if( nums[i]<=0 )
                nums[i]=len+1; 
        }
        int ind;
        for( int i=0; i<len; i++ ){
            ind = abs(nums[i]); 
            if(ind<=len && nums[ind-1]>0 )
                nums[ind-1] = -1*nums[ind-1];
        }
        for( int i=0; i<len; i++ ){
            
            if( nums[i]>0 )
                return i+1;
        }
        return len+1;
    }
};