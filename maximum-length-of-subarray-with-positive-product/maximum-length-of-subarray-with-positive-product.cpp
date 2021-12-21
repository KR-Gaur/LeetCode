class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int firstNeg = -1;
        int l=0, r=0, len = nums.size();
        int ans = 0, negCount = 0; 
        int curProduct=1;
        while(r < len){
            if(nums[r]==0){
                l=r+1;
                r++;
                negCount=0;
                curProduct=1;
                firstNeg=-1;
                continue;
            }
            if(nums[r]<0){
                if(firstNeg==-1) firstNeg=r;
                negCount++;
            }
            if(negCount&1)
                ans = max(ans, r-firstNeg);
            else
                ans = max(ans, r-l+1);
            
            // curProduct=curProduct*nums[r];
            r++;
        }
        return ans;
        
    }
};