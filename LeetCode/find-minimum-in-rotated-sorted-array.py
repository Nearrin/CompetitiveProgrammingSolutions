class Solution:
    def findMin(self, nums: List[int]) -> int:
        v=nums[0]
        l=0
        r=len(nums)-1
        if nums[r]>=v:
            return v
        while l+1<r:
            m=(l+r)//2
            if nums[m]>=v:
                l=m
            else:
                r=m
        return nums[l+1]
        
