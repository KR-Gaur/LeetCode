class Solution {
public:
    int robHouse(vector<int>& nums, int s, int e) {
        // int numberOfHouses = nums.size();
        // if( numberOfHouses == 1)
        //     return nums[0];
        int t0 = 0;
        int t1 = nums[s];
        int t3;
        for( int i=s+1; i<e; i++ ){
            t3 = max(nums[i]+t0, t1);
            t0=t1;
            t1=t3;
        }
        return max(t1,t0);
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) 
            return nums[0];
        return max(robHouse(nums, 0,size-1), robHouse(nums, 1,size));    
    }
};