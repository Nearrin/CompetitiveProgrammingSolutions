class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if nums[0]>target or nums[-1]<target:
            return -1
        if nums[-1]==target:
            return len(nums)-1
        l,r=0,len(nums)-1
        while l+1<r:
            m=(l+r)//2
            if nums[m]>target:
                r=m
            else:
                l=m
        if nums[l]==target:
            return l
        return -1
