class Solution:
    def minMoves(self, nums: List[int]) -> int:
        m=min(nums)
        return sum(nums)-len(nums)*m
