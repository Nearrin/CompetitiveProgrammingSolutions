class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l=0
        r=len(nums)-1
        if nums[l]>target:
            return 0
        if nums[r]<=target:
            if nums[r]==target:
                return r
            else:
                return r+1
        #nums[l]<=target<nums[r]
        while l+1<r:
            m=int((l+r)//2)
            if nums[m]<=target:
                l=m
            else:
                r=m
        if nums[l]==target:
            return l
        return r
