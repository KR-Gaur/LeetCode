class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1,m2,M1,M2,max;
        
        vector<int>mini(nums.size());
        vector<int>maxi(nums.size());
        mini[0]=nums[0];
        maxi[0]=nums[0];
        max = maxi[0];
        for(int i=1;i<nums.size();i++){
            //min[oli]
            m1 = std::min(nums[i],nums[i]*mini[i-1]);
            m2 = std::max(nums[i],nums[i]*mini[i-1]);
            
            M1 = std::min(nums[i],nums[i]*maxi[i-1]);
            M2 = std::max(nums[i],nums[i]*maxi[i-1]);
            
            mini[i] = std::min(m1,M1);
            maxi[i] = std::max(m2,M2);
            if(maxi[i]>max) max=maxi[i];
        }
        return max;
    }
};