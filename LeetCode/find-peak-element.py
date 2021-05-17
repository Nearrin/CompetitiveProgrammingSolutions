class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        nums=[min(nums)-1]+nums+[min(nums)-1]
        l=0
        r=len(nums)-2
        while l+1!=r:
            m=(l+r)//2
            if nums[m]<nums[m+1]:
                l=m
            else:
                r=m
        return r-1
        
