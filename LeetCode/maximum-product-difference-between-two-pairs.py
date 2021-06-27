class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        nums=sorted(nums)
        a,b=nums[:2]
        c,d=nums[-2:]
        return c*d-a*b
