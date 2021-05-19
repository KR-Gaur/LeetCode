class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        
        nums.sort()
        md = nums[len(nums)//2]
        ans = 0
        for i in nums:
            ans = ans + abs(i- md)
        
        return ans