class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int len = nums.size()-1;
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
        return -1;
    }
};