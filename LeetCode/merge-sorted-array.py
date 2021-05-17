class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        a=nums1[:m]
        b=nums2[:n]
        c=[]
        pa=0
        pb=0
        while pa<m or pb<n:
            if pa>=m:
                c.append(b[pb])
                pb+=1
            elif pb>=n:
                c.append(a[pa])
                pa+=1
            elif a[pa]<b[pb]:
                c.append(a[pa])
                pa+=1
            else:
                c.append(b[pb])
                pb+=1
        for i,v in enumerate(c):
            nums1[i]=v
        
