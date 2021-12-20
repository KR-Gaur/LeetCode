class Solution {
public:
    bool canJump(vector<int>& nums) {
        if( nums.size() == 1 ) return true;
        int len = nums.size();
        int p = 0;
        int q = 0;
        // 1 0 1
        while(q<nums[p] && q<len) q++;
        while(p!=q && q<len){
            ++p;
            if(q<nums[p]+p)
                q = nums[p]+p;
        }
        if(q>=len-1)
            return true;
        return false;
    }
};