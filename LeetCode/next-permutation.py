def reverse(a,l,r):
    while l<r:
        a[l],a[r]=a[r],a[l]
        l+=1
        r-=1

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        p=len(nums)-1
        while p and nums[p-1]>=nums[p]:
            p-=1
        if p:
            q=p
            for i in range(p,len(nums)):
                if nums[i]>nums[p-1] and nums[i]<=nums[q]:
                    q=i
            nums[p-1],nums[q]=nums[q],nums[p-1]
        reverse(nums,p,len(nums)-1)
