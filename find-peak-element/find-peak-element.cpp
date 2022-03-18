class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return 0;
        len--;
        if(nums[0]>nums[1])
            return 0;
        if(nums[len]>nums[len-1])
            return len;
        int low = 0, high = len;
        while(low<high){
            int mid = low+(high-low)/2;
            if(mid!=0 && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if(nums[mid-1] < nums[mid])
                low = mid+1;
            else
                high = mid;
            
        }
        return 0;
    }
};