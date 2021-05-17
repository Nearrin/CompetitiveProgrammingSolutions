class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        from collections import defaultdict
        cnt=defaultdict(int)
        for v in nums1:
            cnt[v]+=1
        ans=[]
        for v in nums2:
            if cnt[v]>0:
                ans.append(v)
                cnt[v]-=1
        return ans
