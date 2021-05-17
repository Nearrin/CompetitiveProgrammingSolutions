class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        a=sorted(nums1+nums2)
        n=len(a)
        if n%2==1:
            return a[n//2]
        return (a[n//2-1]+a[n//2])/2
