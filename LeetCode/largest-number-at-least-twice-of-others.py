class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        m=max(nums)
        return nums.index(m) if all(v*2<=m or v==m for v in nums) else -1
