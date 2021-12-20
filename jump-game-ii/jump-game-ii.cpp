class Solution {
public:
    int jump(vector<int>& nums) {
        int curEnd = 0;
        int curFarthest = 0;
        int len = nums.size();
        int jumps = 0;
        for( int i=0; i<len-1; i++ ){
            curFarthest = max(curFarthest, nums[i]+i);
            if( curEnd == i ){
                jumps++;
                curEnd = curFarthest;
            }
        }
        return jumps;
    }
};